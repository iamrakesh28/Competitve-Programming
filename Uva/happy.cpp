#include <bits/stdc++.h>

using namespace std;

pair <int,int> seq(int *arr,int mod,int start,int end)
{
	int cnt=0,len=0,s=start,e,i;
	pair <int,int> p(start,start-1);
	for(i=start;i<=end;++i)
	{
		if(arr[i%mod] == 0)
		{
			if(len < cnt)
			{
				len = cnt;
				p.first = s%mod;
				p.second = (i-1)%mod;	
			}
			cnt=0;
			s = i+1;
		}
		else
		cnt++;
	}
	if(cnt > len)
	{
		len = cnt;
		p.first = s%mod;
		p.second = (i-1)%mod;	
	}
	return p;
}
int main()
{
	int n,q,k;
	bool one = false;
	scanf("%d%d%d",&n,&q,&k);
	int *arr = new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",arr+i);
		if(arr[i])
		one = true;
	}
	pair <int,int> p1 = seq(arr,n,0,n-1);
	pair <int,int> q1 = seq(arr,n,0,2*n-1);
	int len1,len2;
	pair <int,int> curr,prev;
	len1 = p1.second-p1.first+1;
	if(q1.first > q1.second)
	{
		len2 = q1.second + 1;
		len2 += n-q1.first;
	}
	else
	len2 = len1;
	if(len2 <= len1)
	{
		curr = p1;
		prev = seq(arr,n,p1.second+1,n+p1.first-1);
	}
	else
	{
		curr = q1;
		prev = seq(arr,n,(q1.second+1)%n,q1.first-1);
	}
	char ch = getchar_unlocked();
	for(int i=0;i<q;++i)
	{
		ch = getchar_unlocked();
		if(ch == '!')
		{
			curr.first = (curr.first + 1)%n;
			curr.second = (curr.second + 1)%n;
			prev.first = (prev.first + 1)%n;
			prev.second = (prev.second + 1)%n;
		}
		else
		{
			if(one == false)
			{
				cout<<"0\n";
				continue;
			}
			if(curr.first > curr.second)
			{
				int max1 = prev.second-prev.first+1;	
				//cout<<max1<<"\n";
				max1 = max(max1,curr.second+1);
				max1 = max(max1,n-curr.first);
				cout<<min(max1,k)<<"\n";
			}
			else
			cout<<min(curr.second-curr.first+1,k)<<"\n";
		}
	}
	return 0;
}



