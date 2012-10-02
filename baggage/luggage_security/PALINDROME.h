#include <stdio.h>
#include <stdlib.h>

int palindrome(int n)
{
	int i,m=n,l=1;
	
	while(1)
		if(m/10 != 0)
		{
			l++;	//number of digits
			m = m/10;
		}
		else
			break;

	m = n;
	int *a;		//Storing digits in an array
	
	a = (int *)malloc(l*sizeof(int));
		
	for(i=0;i<l;i++)
	{	
		a[l-i-1] = m % 10;		
		m = m/10;
	}	
	
	for(i=0;i<(l/2);i++)
	{
		if(a[i]!=a[l-i-1])
			return -1;		
	}
	return 1;			
}
