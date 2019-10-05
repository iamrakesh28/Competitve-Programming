#include<stdio.h>
#include<stdlib.h>

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,front=1,back=1;
		scanf("%d",&n);
		long int *fing=(long int *)malloc(sizeof(long int)*n);
		long int *sheath=(long int *)malloc(sizeof(long int)*n);
		for(int i=0;i<n;++i)
		{
			scanf("%ld",fing+i);
		}
		for(int i=0;i<n;++i)
		{
			scanf("%ld",sheath+i);
		}
		for(int i=0;i<n;++i)
		{
			if(fing[i]>sheath[i])
			{
				front=0;
				break;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(fing[i]>sheath[n-i-1])
			{
				back=0;
				break;
			}
		}
		if(front&&back)
		{
			printf("both\n");
		}
		else if(front)
		{		
			printf("front\n");
		}
		else if(back)
		{
			printf("back\n");
		}
		else
		{
			printf("none\n");
		}
	}
	return 0;
}
