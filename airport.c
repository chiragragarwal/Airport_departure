#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
	
int main()
{
	takeInputs();
	
	FILE *f = fopen("Ids.txt","w");
	
	printf("I am the AIRPORT PROCESS. PID: %d ; Parent ID : %d\n",getpid(),getppid());
	
	boardPid = fork();
	if(boardPid == 0)
	{
		board_pass(user);
		exit(4);	
	}
	
	waloPid = fork();
	if(waloPid == 0)
	{
		wait_lounge(user);
		exit(4);	
	}
	
	secPid = fork();
	if(secPid == 0)
	{
		security(user);
		exit(3);	
	}
		
	immPid = fork();
	if(immPid == 0)
	{
		immigration(user);
		exit(2);	
	}
		
	bagPid = fork();
	if(bagPid == 0)
	{
		baggage(user);
		exit(1);	
	}
	fprintf(f,"%d ",bagPid);
	fprintf(f,"%d ",immPid);
	fprintf(f,"%d ",secPid);	
	fprintf(f,"%d ",waloPid);
	fprintf(f,"%d ",boardPid);
	fclose(f);
	
	//Main function block
	int y,i,j;	
	for(y=0;y<allowed;y++)
	{
		
		printf("\nMain User number : %d => \n",y);
		sleep(1);
		kill(bagPid,SIGCONT);
		waitpid(bagPid,&status,WUNTRACED);	
		
		kill(immPid,SIGCONT);
	}
	
	kill(getpid(),SIGSTOP);
	
	int wait_count;
	f = fopen("./board_pass/wait_count.txt","r");
	fscanf(f,"%d",&wait_count);
	fclose(f);
	
	printf("\nAIRPORT SPEAKING ==> Total number of passengers arrived at airport : %d\n",allowed);
	printf("\nAIRPORT SPEAKING ==> Total number of passengers boarded : %d\n",allowed-wait_count);
		
	printf("\nAIRPORT SPEAKING ==> Flight number %d ready for departure with %d passengers\n",getpid(),allowed-wait_count);
	
	while(wait(NULL)!= -1);

	return 0;
}
