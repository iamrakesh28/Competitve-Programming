#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,energy=0,cost=0;
	scanf("%d",&n);
	int *arr=(int *)malloc((n+1)*sizeof(int));
	arr[0]=0;
	for(int i=1;i<n+1;++i)
	{
		scanf("%d",arr+i);
		energy+=(arr[i-1]-arr[i]);
		if(energy<0)
		{
			cost+=-energy;
			energy=0;
		}
		
	}
	printf("%d\n",cost);
	return 0;
}