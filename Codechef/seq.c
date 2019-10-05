#include <stdio.h>
#include <stdlib.h>

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int n;
		scanf("%d",&n);
		int *arr=(int *)malloc(sizeof(int)*n);
		int even=0,odd=0;
		for(int j=0;j<n;++j)	
		{
			scanf("%d",arr+j);
			if(arr[j]%2==0)
			even++;
			else
			odd++;
			
		}
		int oddnum=odd%2;
		int evenq,evenr;
		evenq=even+odd/2;
		for(int j=0;evenq>0;++j)
		{
			int num=evenq;
			evenq=evenq/2;
			evenr=num%2;
			if(evenr%2==0)
			evenr==0;
		}
		printf("%d\n",oddnum+evenr);
		
	}
	return 0;
}