#include <stdio.h>
#include <stdlib.h>

long int min(long int x, long int y)
{
	if(x < y)
	return x ;
	return y ;
}

void subtract(long int *freq, long int val, int i)
{
	if(freq[i])
	{
		if(val > freq[i])
		{
			freq[i] = 0;
			subtract(freq,val - freq[i] , i-1);
		}
		else
		{
			freq[i] = freq[i] - val;
			return ;
		}
	}
	else
	subtract(freq,val, i-1);
}

long int max(long int *freq, long int sum)
{
	int check = 0;
	long int total=0,val;
	for(int i = 3; i > 0; --i)
	{
		if(freq[i])
		{
			printf("%ld %ld %d\n",sum, freq[i],i);
			sum -= freq[i];
			if(!check)
			{
				val = min(freq[i],sum-1);
				if(val > 0)
				{
					total += val;
					check = 1;
					subtract(freq,val+1,i-1);
					sum = sum - val - 1;
				}                        
			}
			else
			{
				val = min(freq[i],sum);
				total += val;
				subtract(freq,val,i-1);
				sum -= val; 
			
			}
		}
	}
	return total;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int sum = 0;
		long int *freq = (long int *)malloc(sizeof(long int)*26);
		for(int i = 0 ;i < 4; ++i)
		{
			scanf("%ld",&freq[i]);
			sum += freq[i];
		}
		long int maximum = max(freq,sum);
		printf("%ld\n",maximum);
	}
	return 0;
}
