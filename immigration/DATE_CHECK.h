#include<stdio.h>
#include<stdlib.h>

/* Returns 1 if first date is less than second date	, else returns -1 	*/

int date_check(int a,int b,int c,int x,int y,int z)
{
	if(c>z)
		return -1;
	else if(c<z)
		return 1;
	else
		{
			if(b>y)
				return -1;
			else if(b<y)
				return 1;
			else
			{
				if(a>x)
					return -1;
				else 
					return 1;
			}	
		}
}

//Print FAIL is check = 0; SUCCESSFUL if check = 1
void BP_print(char *ticket_no,int check)
{
	char path[50] = "./baggage/passengers/";
	strcat(path,ticket_no);

	FILE *p=fopen(path,"a");
	if(p == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	if(check==0)
		fprintf(p,"\nIMMIGRATION NOT SUCCESSFUL");
	else
		fprintf(p,"\nIMMIGRATION SUCCESSFUL");
	
	fclose(p);
	return;
}	
