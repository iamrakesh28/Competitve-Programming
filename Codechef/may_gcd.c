#include <stdio.h>

#define loop(x,y) for(int i=y;i<x;++i)

int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,GCD,num,temp;
		scanf("%d%d%d",&n,&num,&temp);
		GCD = gcd(num,temp);
		loop(n,2)
		{
			scanf("%d",&num);
			GCD = gcd(GCD,num);
		}
		if(GCD == 1)
		printf("0\n");
		else
		printf("-1\n");
	}
	return 0;
}
