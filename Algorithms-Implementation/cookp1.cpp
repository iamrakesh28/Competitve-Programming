#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
	int n;
	scanf("%d",&n);
	long int val;
	bool *arr = new bool[n];
	memset(arr,false,sizeof(bool)*n);
	for(int i=0;i<n;++i)
	{
		cin>>val;
		if(val <= n)
		arr[val-1] = true;
	}
	int count=0;
	for(int i=0;i<n;++i)
	{
		if(arr[i] == true)
		count++;
	}
	cout<<n-count<<endl;
	delete [] arr;
	}
	return 0;
}
