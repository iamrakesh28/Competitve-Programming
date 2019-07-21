#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,count=1,one=0;
	scanf("%d",&n);
	int bits,dist;//*arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&bits);
		if(bits)
		{
						
			if(one==1)
			{
				one=1;
				count*=i-dist;
				dist=i;
			}
			else
			{
				dist=i;
				one++;
			}
		}
	}
	if(one==0)
	count=0;
	printf("%d\n",count);
	return 0;
}
