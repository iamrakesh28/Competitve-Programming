#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,i;
	cin>>n>>m;
	int r = m%9;
	int q = m/9;
	vector <int> a,b;
	for(i=0;i < q; ++i)
	{
		if(i%2)
		{
			a.push_back(4);
			b.push_back(5);
		}
		else
		{
			b.push_back(4);
			a.push_back(5);			
		}
	}
	if(r)
	{
		if(i%2)
		{
			a.push_back(ceil(r/2));
			b.push_back(floor(r/2));
		}
		else
		{
			b.push_back(ceil(r/2));
			a.push_back(floor(r/2));			
		}
	}
	for(int i=0;i<a.size();++i)
	printf("%d",a[i]);
	cout<<endl;
	for(int i=0;i<b.size();++i)
	printf("%d",b[i]);
	cout<<endl;
	return 0;
}
