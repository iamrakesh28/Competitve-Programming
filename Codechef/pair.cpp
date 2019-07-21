#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long int n,k,pair;
	cin>>n>>k;
	if(k <= n)
	{
		pair = (k-1)/2;
	}
	else
	{
		unsigned long long int diff = k-n;
		if(diff >= n)
		pair = 0;
		else
		{
			diff = n-diff;
			pair = diff/2;
			pair++;
		}
	}
	cout<<pair<<endl;
	return 0;
}
