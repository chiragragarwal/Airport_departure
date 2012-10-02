#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

#include "PASSPORT.h"
#include "VISA.h"

int retP, retV;
	
void immigration(myUser *user)
{	
	FILE *f = fopen("Ids.txt","r");
	fscanf(f,"%d",&bagPid);
	fscanf(f,"%d",&immPid);	
	fscanf(f,"%d",&secPid);	
	fscanf(f,"%d",&waloPid);
	fscanf(f,"%d",&boardPid);
	fclose(f);
		
		f = fopen("./immigration/imm_Ids.txt","w");
				
		visaPid = fork();
		if(visaPid == 0)
		{
			retV = VISA(user);
			exit(2);
		}						
		
		passPid = fork();
		if(passPid == 0)
		{
			retP = passport(user);
			exit(1);
		}

		fprintf(f,"%d ",passPid);
		fprintf(f,"%d ",visaPid);

		fclose(f);
		
	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);
		
		sleep(1);
		kill(passPid,SIGCONT);
		waitpid(passPid,&status,WUNTRACED);
		
		int PS, VS;
		
		f = fopen("./immigration/Pass_Status.txt","r");
		fscanf(f,"%d",&PS);
		fclose(f);
		
		if(PS == 1)		//passport successful
		{
			sleep(1);
			kill(visaPid,SIGCONT);
			waitpid(visaPid,&status,WUNTRACED);
			
			f = fopen("./immigration/Visa_Status.txt","r");
			fscanf(f,"%d",&VS);
			fclose(f);
		
			if(y==0)
				f = fopen("Imm_Status.txt","w");
			else
				f = fopen("Imm_Status.txt","a");
			
			if(VS == 1)		//VISA successful
			{
				fprintf(f,"%d",1);
			}
			else
			{
				fprintf(f,"%d",0);
			}
			
		}
		else
		{
			if(y==0)
				f = fopen("Imm_Status.txt","w");
			else
				f = fopen("Imm_Status.txt","a");
				
			fprintf(f,"%d",0);
		}		
		fclose(f);
		
		sleep(1);
		kill(secPid,SIGCONT);
		
	}
	while(wait(NULL)!= -1);
}
