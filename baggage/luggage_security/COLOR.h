#include <stdio.h>
#include <stdlib.h>

int search(int *s, int key, int Ls)
{
	int i;
	for(i=0;i<Ls;i++)
		if(s[i]==key)
			return 1;
		else if(s[i]==-1)
			return -1;
	return -1;
}

int color(int n)
{
	int i,j,m=n,l=1,k,Ls;
	
	while(1)
		if(m/10 != 0)
		{
			l++;	//number of digits
			m = m/10;
		}
		else
			break;

	m = n;
	Ls = l*(l+1)/2 ;			//length of search array
	int *a, *s, *M;		//Storing digits in an array
	
	a = (int *)malloc(l*sizeof(int));
	M = (int *)malloc(l*sizeof(int));
	s = (int *)malloc(Ls*sizeof(int));
	
	for(i=0;i<l;i++)
	{
		if(m%10 == 1)		//if one of digits is 1, then NOT colorful
			return -1;
				
		a[l-i-1] = m % 10;		
		s[i] = m%10;
		M[l-i-1] = m%10;
		
		m = m/10;
	}
	
	for(i=l;i<Ls;i++)
		s[i] = -1;
		
	int count = l;	
	int temp;	
	
	for(i=1;i<l;i++)
	{
		k = i;
		for(j=0;j<(l-i);j++)
		{
			temp = M[k]*a[j];			
			if(search(s,temp,Ls) == 1)
				return -1;
			
			M[k] = temp;
			s[count] = temp;
			count++; k++;
		}					
	}	
	return 1;			
}
