#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,result=0,val;
	scanf("%d",&n);
	//int *arr = new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&val);
		result = result | val;
	}
	cout<<result<<endl;
	return 0;
}
