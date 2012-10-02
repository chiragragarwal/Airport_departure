#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#include "luggage_security/LUGGAGE.h"
#include "weight/WEIGHT.h"
#include "boarding_pass/BOARDING_PASS.h"

int retL, penalty, retB;
		
void baggage(myUser *user)
{
	
	FILE *f = fopen("Ids.txt","r");
	fscanf(f,"%d",&bagPid);
	fscanf(f,"%d",&immPid);	
	fscanf(f,"%d",&secPid);
	fscanf(f,"%d",&waloPid);	
	fscanf(f,"%d",&boardPid);
	fclose(f);
	
		f = fopen("./baggage/bag_Ids.txt","w");
		bpPid = fork();
		if(bpPid == 0)
		{
			boarding_pass(user);
			exit(3);
		}
		
		wtPid = fork();
		if(wtPid == 0)
		{
			weight_check(user);
			exit(2);
		}
		
		lugPid = fork();
		if(lugPid == 0)
		{
			luggage_security(user);
			exit(1);
		}
		fprintf(f,"%d ",lugPid);
		fprintf(f,"%d ",wtPid);
		fprintf(f,"%d ",bpPid);
	
		fclose(f);

	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);
			
		sleep(1);
		kill(lugPid,SIGCONT);
		waitpid(lugPid,&status,WUNTRACED);
		
		sleep(1);
		kill(wtPid,SIGCONT);
		waitpid(wtPid,&status,WUNTRACED);
		
		sleep(1);
		kill(bpPid,SIGCONT);
		waitpid(bpPid,&status,WUNTRACED);
		
		sleep(1);
		kill(wtPid,SIGCONT);
		waitpid(wtPid,&status,WUNTRACED);
		
		sleep(1);
		kill(lugPid,SIGCONT);
		waitpid(lugPid,&status,WUNTRACED);
	
		sleep(1);
	}
	
	while(wait(NULL)!= -1);
	exit(1);
}
