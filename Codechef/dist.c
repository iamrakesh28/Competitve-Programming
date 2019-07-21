#include <stdio.h>
#include <stdlib.h>

int main()
{
	int q;
	scanf("%d",&q);
	int n;
	while(q--)
	{
		long int x;
		scanf("%ld",&x);
		if(x==1)
		{
			printf("1\n");
			continue;
		}
		long int begin=1,end=100000,middle;
		while(end-begin>1)
		{
			middle=(begin+end)/2;	
			if(middle*(middle+1)/2>x)
			{
				end=middle;
			}
			else if(middle*(middle+1)/2==x)
			{
				printf("%ld\n",middle);
				goto lb;
			}
			else
			{
				begin=middle+1;
			}
		}
		//end++;
		long int num1=begin*(begin+1)/2;
		long int num2=end*(end+1)/2;
		if(x-num1<1+num2-x)
		{
			printf("%ld\n",begin+x-num1);
		}
		else
		{
			printf("%ld\n",end+num2-x);
		}
		lb:;
	}
	return 0;
}
