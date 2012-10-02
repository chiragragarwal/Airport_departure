#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include "DATE_CHECK.h"

int passport(myUser *user)
{
	FILE *f = fopen("./immigration/imm_Ids.txt","r");
	fscanf(f,"%d",&passPid);
	fscanf(f,"%d",&visaPid);
	fclose(f);	
	
	for(y=0;y<allowed;y++)
	{	
		kill(getpid(),SIGSTOP);	
	
		char *entry_date = user[y].entry_date, *pass_expiry = user[y].pass_expiry;
		char *ret_flight_date = user[y].ret_flight_date, *ticket_no = user[y].ticket_no;
		int ret_ticket = user[y].ret_ticket;
	
		int Cdate,Cmonth,Cyear;
		int Pdate,Pmonth,Pyear;
		int Rdate,Rmonth,Ryear;
		int i;
	
		Cdate = atoi(entry_date);
		Cmonth = atoi(entry_date+3);
		Cyear = atoi(entry_date+6);
	
		Pdate = atoi(pass_expiry);
		Pmonth = atoi(pass_expiry+3);
		Pyear = atoi(pass_expiry+6);
	
		if(ret_ticket==1)
		{
			Rdate = atoi(ret_flight_date);
			Rmonth = atoi(ret_flight_date+3);
			Ryear = atoi(ret_flight_date+6);
		}

		i = date_check(Cdate,Cmonth,Cyear,Pdate,Pmonth,Pyear);
	
		f = fopen("./immigration/Pass_Status.txt","w");
		
		if(i==-1)	//Immigration Failure
		{
			BP_print(ticket_no,0);
			fprintf(f,"%d",0);
		}			
		else if(ret_ticket==1)
		{
			i = date_check(Rdate,Rmonth,Ryear,Pdate,Pmonth,Pyear);
			if(i==-1)	//Immigration Failure
			{
				BP_print(ticket_no,0);
				fprintf(f,"%d",0);
			}	
			else
			{
				fprintf(f,"%d",1);
			}	
		}	
		fclose(f); 
	}
	while(wait(NULL)!= -1);
	exit(1);
}
