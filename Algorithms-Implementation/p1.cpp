#include <bits/stdc++.h>

using namespace std;

int minm(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int n,k,min;
	cin>>n>>k;
	char ch;
	int arr[26] = {0};
	for(int i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		arr[ch - 'A']++;
	}
	min = arr[0];
	for(int i=1;i<k;++i)
	min = minm(arr[i],min);
	cout<<k*min<<endl;
	return 0;
}
