#include <bits/stdc++.h>

#define PRIME 1000000007
using namespace std;

long int costfun(int n,long int *fact,vector <long int> & array)
{
	int time=1;
	long int cost=0;
	for(int i=n-1;i>=0;--i)
	{
		cost=(cost+(array[i]*(fact[time]%PRIME))%PRIME)%PRIME;
		time++;
	}
	return cost;
}

int main()
{
	long int fact[100005];
	int q;
	fact[0]=1;
	for(int i=1;i<100005;++i)
	{
		fact[i]=((fact[i-1]%PRIME)*(i))%PRIME;
	}
	scanf("%d",&q);
	while(q--)
	{
		int n,num;
		long int cost;
		vector <long int> array;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num);
			array.push_back(num);
		}
		sort(array.begin(),array.end());
		cost=costfun(n,fact,array);
		printf("%ld\n",cost);
	}
	return 0;
}
