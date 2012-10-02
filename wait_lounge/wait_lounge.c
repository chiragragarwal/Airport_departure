#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include <time.h>

#include "CAFE.h"
#include "RESTROOM.h"

void wait_lounge(myUser *user)
{
	FILE *f = fopen("Ids.txt","r");
	fscanf(f,"%d",&bagPid);
	fscanf(f,"%d",&immPid);
	fscanf(f,"%d",&secPid);	
	fscanf(f,"%d",&waloPid);
	fscanf(f,"%d",&boardPid);
	fclose(f);	

	f = fopen("./wait_lounge/wait_Ids.txt","w");
				
		cafePid = fork();
		if(cafePid == 0)
		{
			cafe(user);
			exit(2);
		}						
		
		restPid = fork();
		if(restPid == 0)
		{
			restroom(user);
			exit(1);
		}

		fprintf(f,"%d ",restPid);
		fprintf(f,"%d ",cafePid);

	fclose(f);
	
	int wait_count=0;
	
	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);		
		
		int I;
		f = fopen("Imm_Status.txt","r");
		fseek(f,y,SEEK_SET);
		fscanf(f,"%d",&I);	
		fclose(f);
		
		if(I==1)	 //not the last passenger & successful Immigration
		{	
			int choice;
			srand(time(NULL));
			choice = rand()%15 + 1;
		
			f = fopen("./wait_lounge/count.txt","w");	
			fprintf(f,"%d",y);
			fclose(f);			
				
			if(choice<=8 && choice>=1)
			{	
				wait_count++;
				kill(cafePid,SIGCONT);
				waitpid(cafePid,&status,WUNTRACED);
			}
			else
			{
				wait_count++;
				kill(restPid,SIGCONT);
				waitpid(restPid,&status,WUNTRACED);
			}
			wait_count--;
			
			f = fopen("./board_pass/wait_count.txt","w");
			fprintf(f,"%d",wait_count);
			fclose(f);			
		}
		
	}	//End of FOR loop
	
	kill(boardPid,SIGCONT);
	
	while(wait(NULL)!= -1);
	exit(4);
}

