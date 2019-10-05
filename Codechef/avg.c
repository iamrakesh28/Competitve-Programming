#include <stdio.h>
#include <stdlib.h>

#define M 2000
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,num;
		long int pairs=0;
		scanf("%d",&n);
		long int seq[M+1]={0};
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num);
			//printf("' %d '",num+M/2);
			seq[num+M/2]++;
		}
		for(int i=0;i<=M/2;++i)
		{
			if(seq[i])
			{
				pairs+=seq[i]*(seq[i]-1)/2;
				for(int j=i-1;j>=0;--j)
				{
					if(seq[i+i-j] && seq[j])
					pairs+=seq[j]*seq[i+i-j];
				}
			}
		}
		for(int i=M/2+1;i<=M;++i)
		{
			if(seq[i])
			{
				pairs+=seq[i]*(seq[i]-1)/2;
				for(int j=i+1;j<=M;++j)
				{
					if(seq[i+i-j] && seq[j])
					pairs+=seq[j]*seq[i+i-j];
				}
			}
		}
		printf("%ld\n",pairs);
	}
	return 0;
}
