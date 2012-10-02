#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

#include "COLOR.h"
#include "PALINDROME.h"
#include "SEARCH_DELETE2D.h"

int luggage_security(myUser *user)
{
	FILE *f = fopen("./baggage/bag_Ids.txt","r");
	fscanf(f,"%d",&lugPid);
	fscanf(f,"%d",&wtPid);
	fscanf(f,"%d",&bpPid);
	fclose(f);

	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);	
		char *ticket_no = user[y].ticket_no;
		int nBags = user[y].nBags, *weight = user[y].weight, **contents = user[y].contents ;
	
		int i,danger_count = 0;
		int danger[(nBags-1)*10];	//Except the handbag
	
			for(i=0;i<nBags-1;i++)	//Luggage other than handbag
				for(j=0;j<10;j++)
				{
					if(color(contents[i][j]) == 1 || palindrome(contents[i][j]) == 1)
					{
						danger[danger_count] = contents[i][j];
						danger_count++;
					}
				}
		
			for(t=0;t<danger_count;t++)
				contents = delete2D(contents,danger[t],nBags-1);	//Except the handbag
		
		kill(getpid(),SIGSTOP);
		
			//Printing Dangerous items to terminal
			printf("\n\n User = %d ; No. of dangerous items = %d\n Items are as follows : \n\n",y,danger_count);	
			for(i=0;i<danger_count;i++)
				printf("%d ",danger[i]);
			printf("\n");
		
			//Appending Baggage ID to Boarding Pass		
			char path[50] = "./baggage/passengers/";
			strcat(path,ticket_no);

			FILE *p=fopen(path,"a");
			if(p == NULL)
			{
				printf("ERROR\n");
				exit(1);
			}
			fprintf(p,"\nBaggage_ID:%d",y);
			fclose(p);
		
	}
	while(wait(NULL)!= -1);
	exit(1);
}

