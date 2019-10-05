#include <bits/stdc++.h>

#define pb(x) push_back(x)
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31};

bool isPrime(int val)
{
	for(int i=0;i<11;++i)
	if(val == prime[i])
	return true;
	return false;
}
void backtrack(int mask,int *arr,int n,int cur,int index)
{
	if(index == n)
	{
		if(isPrime(arr[0] + arr[index-1]))
		{
			for(int i=0;i<n-1;++i)
			printf("%d ",arr[i]);
			printf("%d\n",arr[n-1]);
		}
		return;
	}
	for(int i=2;i<=n;++i)
	{
		if((mask >> i) % 2 == 0 && isPrime(i+cur))
		{
			arr[index] = i;
			backtrack((mask | 1 << i),arr,n,i,index+1);
		}
	}
}

int main()
{
	int n,i=0;
	int *arr;
	while(scanf("%d",&n) != EOF)
	{
		arr = new int[n];
		arr[0] = 1;
		if(i)
		putchar('\n');
		printf("Case %d:\n",++i);
		backtrack(2,arr,n,1,1);
		delete [] arr;
	}
	return 0;
}
