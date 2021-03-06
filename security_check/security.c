#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

#include "SECURITY_M.h"
#include "SECURITY_F.h"

int ch;
int ret;

void security(myUser *user)
{
	FILE *f = fopen("Ids.txt","r");
	fscanf(f,"%d",&bagPid);
	fscanf(f,"%d",&immPid);
	fscanf(f,"%d",&secPid);
	fscanf(f,"%d",&waloPid);
	fscanf(f,"%d",&boardPid);	
	fclose(f);	
	
		f = fopen("./security_check/sec_Ids.txt","w");
		
		sec_MPid = fork();
		if(sec_MPid == 0)
		{
			security_M(user);
			exit(2);
		}		
		
		sec_FPid = fork();
		if(sec_FPid == 0)
		{
			security_F(user);	
			exit(1);
		}

		fprintf(f,"%d ",sec_FPid);
		fprintf(f,"%d ",sec_MPid);

		fclose(f);
		
	int flag=0;	
	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);
			
		if(flag==1)
			flag = 0;
			
		f = fopen("Imm_Status.txt","r");
		fseek(f,y,SEEK_SET);
		fscanf(f,"%d",&ch);
		fclose(f);
		
		if(ch == 0)	//Terrorist
		{
			printf("\nPassenger %s %s is thrown out of the airport !\n",user[y].first,user[y].last);
			flag = 1;
		}
		
		if(flag==0)
		{
			printf("\nPassenger %s %s is allowed to board\n",user[y].first,user[y].last);
		
			ret = strcmp(user[y].gender,"M");	

			if(ret==0)	//Male
			{
				printf("\nSending %s %s to SECURITY_MALE \n",user[y].first,user[y].last);
				kill(sec_MPid,SIGCONT);
				waitpid(sec_MPid,&status,WUNTRACED);
			}
		
			else		//Female
			{
				printf("\nSending %s %s to SECURITY_FEMALE \n",user[y].first,user[y].last);
				kill(sec_FPid,SIGCONT);
				waitpid(sec_FPid,&status,WUNTRACED);
			}
		
		}
		
		kill(waloPid,SIGCONT);
		
	}	//End of for loop
	
	while(wait(NULL)!= -1);
	exit(3);
	
}
