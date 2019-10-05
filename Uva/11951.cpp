#include <bits/stdc++.h>

using namespace std;

int land[100][100];
long int prefix[100][100],k,maxarea,cost;

long int sum(int i,int j)
{
	if(i < 0 || j < 0)
	return 0;
	return prefix[i][j];
}

void lower(int i,int j,int n,int m)
{
	long int range,area;
	for(int ki=i;ki<n;++ki)
	{
		for(int p=j;p<m;++p)
		{
			range = sum(ki,p) - sum(ki,j-1) - sum(i-1,p) + sum(i-1,j-1);
			area = (ki-i+1)*(p-j+1);
			if(range <= k)
			{
				if(area == maxarea)
				cost = min(range,cost);
				else if(area > maxarea)
				{
					maxarea = area;
					cost = range;
				}
			}
		}
	}
}
void ans(int n,int m)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		lower(i,j,n,m);
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int n,m;
		scanf("%d%d%ld",&n,&m,&k);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				scanf("%d",land[i]+j);
				prefix[i][j] = sum(i,j-1) + sum(i-1,j) - sum(i-1,j-1) + land[i][j];
			}
		}
		cost = LONG_MAX;
		maxarea = 0;
		ans(n,m);
		if(cost == LONG_MAX)
		cost = 0;
		printf("Case #%d: %ld %ld\n",i+1,maxarea,cost);
	}
	return 0;
}
