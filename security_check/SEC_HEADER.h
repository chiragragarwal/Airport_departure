
#include <stdio.h>
#include <stdlib.h>

int s_search(int *s, int key, int Ls)
{
	int i;
	for(i=0;i<Ls;i++)
		if(s[i]==key)
			return 1;
		else if(s[i]==-1)
			return -1;
	return -1;
}

int s_color(int n)
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
			if( s_search(s,temp,Ls) == 1 )
				return -1;
			
			M[k] = temp;
			s[count] = temp;
			count++; k++;
		}					
	}	
	return 1;			
}

int s_palindrome(int n)
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

int s_isprime(int num)
{
	int i = 2;	//as 2 is the first prime number
    while(i*i <= num)  	//as good as comparing i < sqrt(num)
    {
        if(num % i == 0)
            return -1;		//Not a prime number, return -1
        i++;
    }
    return 1;				//Prime number
}

int s_search2D(int **a, int key, int nBags)
{
	int i,j;
	for(i=0;i<nBags;i++)
		for(j=0;j<10;j++)
			if(a[i][j] == key)
				return(10*i + j);
	return -1;	//not found
}


int **s_delete2D(int **contents, int key, int nBags)
{
	int p = s_search2D(contents,key,nBags);
	//printf("\nkey = %d ; p = %d\n",key, p);
	
	if(p == -1)
		return contents;
		
	int i = p/10;
	p = p%10;
	
	//printf("\ni = %d ; j = %d\n",i,p);
	
	while(contents[i][p] != -1 && p<9)
	{
		//printf("iteration p = %d",p);
		contents[i][p] = contents[i][p+1];
		p++;
	}
	contents[i][p] = -1;	//-1 to indicate a blank position
	return contents;
	
}

