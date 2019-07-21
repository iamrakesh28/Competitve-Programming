#include <bits/stdc++.h>

using namespace std;

bool solve(int *a,int *b,int n)
{
	for(int i=0;i<n-2;++i)
	{
		if(a[i] != b[i])
		{
			int n = b[i]-a[i];
			if(n < 0)
			return false;
			a[i] = b[i];
			a[i+1] += 2*n;
			a[i+2] += 3*n;
		}
		//cout<<a[i]<<endl;
	}
	if(a[n-2] == b[n-2] && a[n-1] == b[n-1])
	return true;
	return false;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		int *a = new int[n];
		int *b = new int[n];
		for(int i=0;i<n;++i)
		scanf("%d",a+i);
		for(int i=0;i<n;++i)
		scanf("%d",b+i);
		bool poss = solve(a,b,n);
		if(poss == true)
		printf("TAK\n");
		else
		printf("NIE\n");
		delete [] a,b;
	}
	return 0;
}
