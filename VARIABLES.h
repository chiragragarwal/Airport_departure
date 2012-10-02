#include<stdlib.h>
#include<stdio.h>

typedef struct User
{
	int ret_ticket;	
	char entry_time[6],entry_date[12],ticket_no[10],flight_no[7],flight_time[6], flight_date[12], destination[20];
	char ret_ticket_no[10],ret_flight_no[7],ret_flight_time[6], ret_flight_date[12], ret_destination[20];
	char passport_no[10], pass_expiry[12], nationality[20];
	char VISA_expiry[12], VISA_country[20];
	char first[20],last[20], gender[2];
	int age, imm_status;
	int nBags;
	int *weight, **contents;
} myUser;

myUser *user, temp;

int N,y, allowed=0;
int i,j,t,en,fl, status;	

pid_t bagPid, lugPid, wtPid, bpPid;
pid_t immPid, passPid, visaPid;
pid_t secPid, sec_Mpid, sec_Fpid;
pid_t waloPid, cafePid, restPid;
pid_t boardPid;

extern void takeInputs();
