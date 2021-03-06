#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include <time.h>

void restroom(myUser *user)
{	
	while(1)
	{	
		kill(getpid(),SIGSTOP);
			
		int  Rcount;
		FILE *f = fopen("./wait_lounge/count.txt","r");	
		fscanf(f,"%d",&Rcount);
		fclose(f);

		if(Rcount < allowed)
		{
			int restNum;
			srand(time(NULL));
			restNum = rand()%(Rcount+1) + 1;			
			
			printf("\n\nPassenger %s %s , Ticket No : %s has entered Restroom%d\n\n",
					user[Rcount].first,user[Rcount].last,user[Rcount].ticket_no, restNum);
			sleep(1);
			
		}
		else if(Rcount == allowed-1)
		{
			kill(getpid(),SIGSTOP);
			exit(1);
		}
	}
}
