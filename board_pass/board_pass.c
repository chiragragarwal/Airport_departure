#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>

void board_pass(myUser *user)
{

	kill(getpid(),SIGSTOP);
	
	FILE *f = fopen("Ids.txt","r");
	fscanf(f,"%d",&bagPid);
	fscanf(f,"%d",&immPid);
	fscanf(f,"%d",&secPid);	
	fscanf(f,"%d",&waloPid);
	fscanf(f,"%d",&boardPid);
	fclose(f);	
	
	printf("\n\n----------------Beginning Boarding Pass Process-----------------\n");
	printf("\n\n++++ ALL PASSENGERS ARE REQUESTED TO MOVE TO THE GATE ++++\n\n");
	
	int wait_count;
	f = fopen("./board_pass/wait_count.txt","r");
	fscanf(f,"%d",&wait_count);
	fclose(f);
	
	if(wait_count!=0)
	{
		printf("\n\nThis is the last boarding call for all the remaining passengers !!\n\n");
		sleep(2);	
	}
	
	f = fopen("./wait_lounge/wait_Ids.txt","r");
	fscanf(f,"%d",&restPid);
	fscanf(f,"%d",&cafePid);
	fclose(f);
	
	printf("\n\n<========== ENDING THE RESTROOM PROCESS on signal from BOARD PASS ==========>\n\n");
	kill(restPid,SIGSTOP);
	printf("\n\n<========== ENDING THE CAFE PROCESS on signal from BOARD PASS ==========>\n\n");
	kill(cafePid,SIGSTOP);
	printf("\n\n<========== ENDING THE WAIT LOUNGE PROCESS on signal from BOARD PASS ==========>\n\n");
	kill(waloPid,SIGSTOP);
	
	printf("\n\n----------------Ending Boarding Pass Process-----------------\n");
	
	kill(getppid(),SIGCONT);
	exit(4);
}
