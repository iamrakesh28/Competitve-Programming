#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long int isPossible(long int *arr,int n,int h,int num)
{
	long int time=0,q,r=0;
	for(int i=0;i<n;++i)
	{
		q=arr[i]/num;
		if(arr[i]%num)
		{
			r=1;
		}
		time+=q+r;
		if(time>h)
		{
			return 0;
		}
		r=0;
	}
	return 1;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		long int h,max=INT_MIN,begin,end,middle;
		scanf("%d%ld",&n,&h);
		long int *arr=(long int*)malloc(sizeof(long int)*n);
		for(int i=0;i<n;++i)
		{
			scanf("%ld",arr+i);
			if(max<arr[i])
			{
				max=arr[i];
			}
		}
		begin=1,end=max;
		//printf("-%d-",max);
		while(begin!=end)
		{
			middle=(begin+end)/2;
			//printf(" =%d= ",middle);
			long int num=isPossible(arr,n,h,middle);
			if(num)
			{
				end=middle;
				/*printf("%d\n",i);
				break;*/
			}
			else
			{
				begin=middle+1;
			}
		}
		printf("%ld\n",begin);
	}
	return 0;
}
