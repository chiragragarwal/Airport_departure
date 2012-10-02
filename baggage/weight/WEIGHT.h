#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>

int weight_check(myUser *user)
{
	FILE *f = fopen("./baggage/bag_Ids.txt","r");
	fscanf(f,"%d",&lugPid);
	fscanf(f,"%d",&wtPid);
	fscanf(f,"%d",&bpPid);
	fclose(f);
			
	for(y=0;y<allowed;y++)
	{
		int i,penalty = 0;
		
		kill(getpid(),SIGSTOP);
		char *ticket_no = user[y].ticket_no;
		int nBags = user[y].nBags, *weight = user[y].weight;
		
			if(nBags>3)
				for(i=3;i<nBags;i++)
					penalty += 40;

			for(i=0;i<nBags;i++)
				if(weight[i] >= 20)
					penalty += ((weight[i]-20)*2);
		
		kill(getpid(),SIGSTOP);
		
			//Penalty to terminal
			printf("\n\nExtra Penalty Charges = $%d for Ticket Number = %s\n\n",penalty,user[y].ticket_no);
		
			//Appending Penalty to Boarding Pass		
			char path[50] = "./baggage/passengers/";
			
			strcat(path,ticket_no);

			FILE *p=fopen(path,"a");
			if(p == NULL)
			{
				printf("ERROR\n");
				exit(1);
			}
			fprintf(p,"\nPenalty:$%d",penalty);
			fclose(p);
		
	}
	while(wait(NULL)!= -1);
	exit(2);
}
