#include <bits/stdc++.h>

using namespace std;

#define size 1000000

typedef long long int lli;

int main()
{
	int n;
	scanf("%d",&n);
	bool *prime = new bool[size];
	memset(prime,true,sizeof(bool)*size);
	prime[0] = false;
	for(int i=2;i*i<=size;++i)
	{
		if(prime[i-1] == true)
		for(int j = 2*i;j<=size;j+=i)
		prime[j-1] = false;
	}
	lli *arr = new lli[n];
	for(int i=0;i<n;++i)
	cin>>arr[i];
	for(int i=0;i<n;++i)
	{
		lli sq = sqrt(arr[i]);
		//cout<<sq<<endl;
		if(sq*sq != arr[i])
		{cout<<"NO"<<endl; continue;}
		if(prime[sq-1])
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}	
	return 0;
}
