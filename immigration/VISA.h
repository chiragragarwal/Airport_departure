#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int VISA(myUser *user)
{
	FILE *f = fopen("./immigration/imm_Ids.txt","r");
	fscanf(f,"%d",&passPid);
	fscanf(f,"%d",&visaPid);
	fclose(f);		

	for(y=0;y<allowed;y++)
	{	
		
		kill(getpid(),SIGSTOP);	
		
		char *entry_date = user[y].entry_date, *nationality = user[y].nationality, *destination = user[y].destination;
		char *VISA_expiry = user[y].VISA_expiry, *ticket_no = user[y].ticket_no, *ret_flight_date = user[y].ret_flight_date;
		int ret_ticket = user[y].ret_ticket;
		
		int Cdate,Cmonth,Cyear;
		int Vdate,Vmonth,Vyear;
		int Rdate,Rmonth,Ryear;
		int i,d1,d2,reject=0;

		Cdate = atoi(entry_date);
		Cmonth = atoi(entry_date+3);
		Cyear = atoi(entry_date+6);
	
		Vdate = atoi(VISA_expiry);
		Vmonth = atoi(VISA_expiry+3);
		Vyear = atoi(VISA_expiry+6);
	
		if(ret_ticket==1)
		{
			Rdate = atoi(ret_flight_date);
			Rmonth = atoi(ret_flight_date+3);
			Ryear = atoi(ret_flight_date+6);
		}

		i = strcmp(destination,nationality);
		if(i==0)
		{
			d1 = date_check(Cdate,Cmonth,Cyear,Vdate,Vmonth,Vyear);
			if(d1==-1)	//Immigration Failure
				reject = 1;	
		}
		else if(ret_ticket==1)
		{
			d1 = date_check(Cdate,Cmonth,Cyear,Vdate,Vmonth,Vyear);
			d2 = date_check(Rdate,Rmonth,Ryear,Vdate,Vmonth,Vyear);
			if(d1==-1 || d2==-1)	//Immigration Failure
				reject = 1;	
		}
		else
		{
			d1 = date_check(Cdate,Cmonth,Cyear,Vdate,Vmonth,Vyear);
			if(d1==-1)	//Immigration Failure
				reject = 1;	
		}
	
		f = fopen("./immigration/Visa_Status.txt","w");
	
		if(reject==1)
		{
			BP_print(ticket_no,0);
			fprintf(f,"%d",0);
			fclose(f);
		}
		else
		{
			BP_print(ticket_no,1);
			fprintf(f,"%d",1);
			fclose(f);
		}
	
	}
	while(wait(NULL)!= -1);
	exit(1);
}
