#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include<string.h>

int boarding_pass(myUser *user)
{
	FILE *f = fopen("./baggage/bag_Ids.txt","r");
	fscanf(f,"%d",&lugPid);
	fscanf(f,"%d",&wtPid);
	fscanf(f,"%d",&bpPid);
	fclose(f);

	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);
		char *ticket_no = user[y].ticket_no, *gender = user[y].gender;
		int age = user[y].age, seat_no = y;
		
			char path[50] = "./baggage/passengers/";
			strcat(path,ticket_no);

			FILE *p = fopen(path,"w");
			if(p == NULL)
			{
				printf("ERROR IN OPENING THE FILE\n");
				exit(1);
			}	
	
			int meal;
			srand(time(NULL));
			meal = rand()%15 + 1;
	
			char *mealName;
			if(meal>=1 && meal<=5)
				mealName = "Vegetarian";
			else if(meal>=6 && meal<=10)
				mealName = "Non-Vegetarian";
			else
				mealName = "Asian-Vegetarian";
	
			fprintf(p,"%s %d %s Seat_No:%d %s",ticket_no,age,gender,seat_no,mealName);	
			fclose(p);
	}
	while(wait(NULL)!= -1);
	exit(3);
}
