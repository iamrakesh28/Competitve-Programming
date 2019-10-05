#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	long long int s,step,*sum;
	cin>>n>>s;
	long long int *arr = new long long int [n];
	sum = new long long int [n+1];
	sum[0] = 0;
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;++i)
	sum[i+1] = sum[i] + arr[i];
	if(arr[n/2] == s)
	{
		cout<<0<<endl;
		return 0;
	}
	if(arr[n/2] > s)
	{
		int i;
		for(i=n/2;i>=0;i--)
		{
			if(arr[i]<=s)
			break;
		}
		step = (n/2 - i)*s - (sum[n/2+1] - sum[i+1]);
	}
	else
	{
		int i;
		for(i=n/2;i<n;i++)
		{
			if(arr[i]>=s)
			break;
		}
		//cout<<sum[n/2]<<endl;
		step = (i - n/2)*s - (sum[i] - sum[n/2]);
	}
	if(step < 0)
	step = -step; 
	cout<<step<<endl;	
	return 0;
}
