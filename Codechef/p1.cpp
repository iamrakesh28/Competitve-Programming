#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int n,k,count=0,total=0;
		scanf("%d%d",&n,&k);
		long int *arr = new long int[n];
		for(int j=0;j<n;++j)
		scanf("%ld",arr+j);
		sort(arr,arr+n);
		int day=1;
		for(int j=0;j<n;++j)
		{
			if(arr[j] >= day)
			count++;
			if(count == k)
			{
				total += count;
				count = 0;
				day++;
			}
		}
		if(count)
		total += count;
		printf("Case #%d: %d\n",i,total);
	}
	return 0;
}
