#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,day = 0;
		long int index = 1;
		scanf("%d",&n);
		int *people = new int[n];
		long int *sum = new long int[n];
		for(int i=0;i<n;++i)
		{
			scanf("%d",people+i);
			if(i == 0)
			sum[i] = people[i];
			else
			sum[i] = sum[i-1] + people[i];
		}
		while(index < n)
		{
			index += sum[index-1];
			day++;
		}
		printf("%d\n",day);
		delete [] people,sum;
	}
	return 0;
}
