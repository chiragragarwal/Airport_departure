#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void security_F(myUser *user)
{
	FILE *f = fopen("./security_check/sec_Ids.txt","r");
	fscanf(f,"%d",&sec_FPid);
	fscanf(f,"%d",&sec_MPid);
	fclose(f);	
	
	for(y=0;y<allowed;y++)
	{
		kill(getpid(),SIGSTOP);
		
		int **contents = user[y].contents ,nBags = user[y].nBags;
		char *ticket_no = user[y].ticket_no;
		
		int i=nBags-1, danger_count = 0;
		int danger[10];	
	
		for(j=0;j<10;j++)		//check only handbag
		{
			if(s_color(contents[i][j]) == 1 || s_palindrome(contents[i][j]) == 1 || s_isprime(contents[i][j]) == 1)
			{
				danger[danger_count] = contents[i][j];
				danger_count++;
			}
		}
	
		for(t=0;t<danger_count;t++)
			contents = s_delete2D(contents,danger[t],nBags);
		
			//Printing Dangerous items to terminal
			printf("\n\n Ticket No : %s ; No. of dangerous items in HANDBAG = %d\nItems are as follows : \n",ticket_no, danger_count);	
					
			for(i=0;i<danger_count;i++)
				printf("%d ",danger[i]);
			printf("\n");	
	}
	exit(1);
}
