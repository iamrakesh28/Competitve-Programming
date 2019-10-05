#include <stdio.h>
#include <limits.h>

int main()
{
	int n,a,b,i,j;
	scanf("%d%d%d",&n,&a,&b);
	int min=INT_MAX,area,a1,b1;
	for(i=a;i*b<=6*n;++i)
	{
		area=i*b;
		for(j=b;area<6*n;++j)
		{
			area=i*j;
		}
		if(area<min)
		{
			min=area;
			a1=i;
			b1=j-1;
		}
	}
	if(i*b<min)
	{
		min=i*b;
		a1=i;
		b1=b;
	}
	printf("%d\n%d %d\n",min,a1,b1);
	return 0;
}
