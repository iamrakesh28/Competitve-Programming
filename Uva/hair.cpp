#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	long int l;
	scanf("%d%d%ld",&n,&m,&l);
	long int *hair = new long int[n];
	for(int i=0;i<n;++i)
	scanf("%ld",hair+i);
	int i,seg=0;
	for(i=0;i<n;++i)
	{
		if(hair[i] > l)
		{
			if(i >= 1 && hair[i-1] <= l)
			seg++;
			if(i == 0)
			seg++;
		}
	}
	while(m--)
	{
		int t,p,d;
		scanf("%d",&t);
		if(t == 1)
		{
			scanf("%d%d",&p,&d);
			if(hair[p-1] <= l)
			{
				hair[p-1] += d;
				if(hair[p-1] <= l)
				continue;
				if(p < n && hair[p] <= l)
				{
					if(p-2 >= 0 && hair[p-2] <= l)
					seg++;
					if(p-2 < 0)
					seg++;
				}
				else if(p >= n)
				{
					if(p-2 >= 0 && hair[p-2] <= l)
					seg++;
					if(p-2 < 0)
					seg++;
				}
				else 
				{
					if(p-2 >= 0 && hair[p-2] > l)
					seg--;
				}
			}
		}
		else
		printf("%d\n",seg);
	}
	delete []hair;
	return 0;
}
