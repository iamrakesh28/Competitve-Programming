#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,sum=0,val;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&val);
			sum += val;
		}
		if(n == 1)
		{
			printf("-1\n");
			continue;
		}
		val = sum/(n-1);
		if(val*(n-1) != sum || val > n)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",n-val);
	}
	return 0;
}
