#include <bits/stdc++.h>

using namespace std;

bool compare(pair <long int,long int> &a,pair <long int,long int> &b)
{
	if(a.first < b.first)
	return true;
	else if(a.first > b.first)
	return false;
	else
	return (a.second < b.second);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector < pair <long int, long int> >x;
	vector < pair <long int, long int> >y;
	for(int i=0;i<n;++i)
	{
		long int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		x.push_back(make_pair(x1,1));
		x.push_back(make_pair(x2,-1));
		y.push_back(make_pair(y1,1));
		y.push_back(make_pair(y2,-1));
	}
	sort(x.begin(),x.end(),compare);
	sort(y.begin(),y.end(),compare);
	int count = 0,start=0;
	long int left,right,top,bottom;
	for(int i=0;i<2*n;++i)
	{
		if(x[i].second == 1)
		count++;
		else
		count--;
		if(count == n-1 && start == 0)
		{
			start = 1;
			left = x[i].first;
		}
		else if(count == n-1)
		{
			right = x[i].first;
		}
	}
	count =0,start = 0;
	for(int i=0;i<2*n;++i)
	{
		if(y[i].second == 1)
		count++;
		else
		count--;
		if(count == n-1 && start == 0)
		{
			start = 1;
			bottom = y[i].first;
		}
		else if(count == n-1)
		{
			top = y[i].first;
		}
	}
	cout<<left<<" "<<right<<" "<<top<<" "<<bottom<<endl; 
	return 0;
}
