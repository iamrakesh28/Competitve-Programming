#include <stdio.h>
#include <stdlib.h>

int check(int n, int m, int even, int odd, int x)
{
	for(int i=1;i<=m;i+=2)
	{
		if(odd-x>=0)
		{
			n-=x;
			odd-=x;
		}
		else
		{
			n-=odd;
			odd=0;
			break;
		}
	}	
	if(n<=0)
	return 1;

	for(int i=2;i<=m;i+=2)
	{
		if(even-x>=0)
		{
			n-=x;
			even-=x;
		}
		else
		{
			n-=even;
			even=0;
			break;
		}
	}	
	if(n<=0)
	return 1;
	else
	return 0;
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int n,m,k,x;
		scanf("%d%d%d%d",&n,&m,&x,&k);
		char *arr=(char *)malloc(sizeof(char)*(k+1));
		int even=0,odd=0;
		scanf("%s",arr);
		while(*arr!='\0')
		{
			if(*arr=='E')
			even++;
			else
			odd++;
			arr++;
		}
		if(check(n,m,even,odd,x))
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
