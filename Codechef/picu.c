#include <stdio.h>

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int group,sum,D,M,B,A,X,months;
		scanf("%ld%ld%ld%ld%ld",&D,&A,&M,&B,&X);
		if(D >= X)
		{
			printf("0\n");
			continue;
		}
		group = A*M + B;
		months = (X - D)/group;
		sum = X - D - months*group;
		months = months*(M+1);
		if(sum > 0)
		{
			long int count = sum/A;
			sum = sum - count*A;
			if(sum > 0)
			{
				if(count < M)
				months += count + 1;
				else
				months += M + 1;
			}
			else
			months = months + count;
		}
		printf("%ld\n",months);
	}
	return 0;
}
