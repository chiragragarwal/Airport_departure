#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include <time.h>

void cafe(myUser *user)
{	
	while(1)
	{	
		kill(getpid(),SIGSTOP);
			
		int  Ccount;
		FILE *f = fopen("./wait_lounge/count.txt","r");	
		fscanf(f,"%d",&Ccount);
		fclose(f);

		if(Ccount < allowed)
		{
			int cafeNum;
			srand(time(NULL));
			cafeNum = rand()%(Ccount+1) + 1;			
			
			printf("\n\nPassenger %s %s , Ticket Number : %s has entered Cafe%d\n\n",
					user[Ccount].first, user[Ccount].last,user[Ccount].ticket_no , cafeNum);
			sleep(1);

		}
		else if(Ccount == allowed-1)
		{
			kill(getpid(),SIGSTOP);
			exit(2);
		}
	}
}
