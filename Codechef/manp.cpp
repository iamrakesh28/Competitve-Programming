#include <bits/stdc++.h>

using namespace std;

int main()
{
	long int n,num=0;
	cin>>n;
	while(n>1)
	{
		long int l,r;
		l = n/2;
		r = n-l;
		num++;
		n = n/2;
	}
	cout<<++num<<endl;
	return 0;
}
