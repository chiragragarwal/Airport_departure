#include "VARIABLES.h"

void takeInputs()
{
	FILE *f = fopen("INPUT.txt","r");
	if(f == NULL)
	{
		printf("ERROR IN OPENING THE FILE\n");
		exit(1);
	}	
	
	fscanf(f,"%d",&N);	
	
	user = (myUser *)malloc(N*sizeof(myUser));
	
	for(y=0;y<N;y++)
	{
		fscanf(f,"%d",&temp.ret_ticket);		//Return ticket flag	
	
		fscanf(f,"%s",temp.entry_time);		//entry time
		fscanf(f,"%s",temp.entry_date);		//entry date
	
		fscanf(f,"%s",temp.ticket_no);
		fscanf(f,"%s",temp.flight_no);
		fscanf(f,"%s",temp.flight_time);
		fscanf(f,"%s",temp.flight_date);
		fscanf(f,"%s",temp.destination);
	
		if(temp.ret_ticket==1)
		{
			fscanf(f,"%s",temp.ret_ticket_no);
			fscanf(f,"%s",temp.ret_flight_no);
			fscanf(f,"%s",temp.ret_flight_time);
			fscanf(f,"%s",temp.ret_flight_date);
			fscanf(f,"%s",temp.ret_destination);	
		}
	
		fscanf(f,"%s",temp.passport_no);
		fscanf(f,"%s",temp.pass_expiry);
		fscanf(f,"%s",temp.nationality);
	
		fscanf(f,"%s",temp.VISA_expiry);
		fscanf(f,"%s",temp.VISA_country);
	
		fscanf(f,"%s",temp.first);
		fscanf(f,"%s",temp.last);
		fscanf(f,"%s",temp.gender);
		fscanf(f,"%d",&temp.age);
	
		fscanf(f,"%d",&temp.nBags);
	
		temp.weight = (int *)malloc(temp.nBags*sizeof(int));
		
		for(i=0;i<temp.nBags;i++)
			fscanf(f,"%d",&temp.weight[i]);	
	
		//Initialising contents	
		temp.contents = malloc(temp.nBags*sizeof(int *));	
		for(i=0;i<temp.nBags;i++)
			temp.contents[i] = (int *)malloc(10*sizeof(int));
		
		for(i=0;i<temp.nBags;i++)
			for(j=0;j<10;j++)
			{
				fscanf(f,"%d",&t);
				temp.contents[i][j] = t;
			}
			
		en = atoi(temp.entry_time);
		fl = atoi(temp.flight_time);
		if(fl-en <= 4)	//Checking if time is <= 4hours
		{	
			user[allowed] = temp;
			allowed++;
		}
	}	// END OF BIGGEST FOR LOOP
	
	fclose(f);
	return;
}
