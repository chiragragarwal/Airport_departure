#include<stdio.h>
#include<stdlib.h>

int search2D(int **a, int key, int nBags)
{
	int i,j;
	for(i=0;i<nBags;i++)
		for(j=0;j<10;j++)
			if(a[i][j] == key)
				return(10*i + j);
	return -1;	//not found
}


int **delete2D(int **contents, int key, int nBags)
{
	int p = search2D(contents,key,nBags);
	
	if(p == -1)
		return contents;
		
	int i = p/10;
	p = p%10;
	
	while(contents[i][p] != -1 && p<9)
	{
		contents[i][p] = contents[i][p+1];
		p++;
	}
	contents[i][p] = -1;	//-1 to indicate a blank position
	return contents;
	
}


