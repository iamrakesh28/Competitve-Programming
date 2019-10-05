#include <bits/stdc++.h>

using namespace std;

int upper(vector <int> &tail,vector <int> &v,int l,int r,int val)
{
	int m;
	while(r-l > 1)
	{
		m = (l + r)/2;
		if(v[tail[m]] >= val)
		r = m;
		else
		l = m;
	}
	return r;
}

void LIS(vector <int> &v)
{
	int n = v.size();
	vector <int> tail(n,0);
	vector <int> prev(n,-1);
	int len=1;
	for(int i=1;i<n;++i)
	{
		if(v[i] < v[tail[0]])
		tail[0] = i;
		else if(v[i] > v[tail[len-1]])
		{
			prev[i] = tail[len-1];
			tail[len++] = i;
		}
		else
		{
			int pos = upper(tail,v,-1,len-1,v[i]);
			prev[i] = tail[pos-1];
			tail[pos] = i;
		}
	}
	printf("%d\n-\n",len);
	vector <int> seq(len);
	for(int i=tail[len-1];i>=0;i=prev[i])
	seq[--len] = v[i];
	for(int i=0;i<seq.size();++i)
	printf("%d\n",seq[i]);
	return;
}
int main()
{
	vector <int> v;
	int val;
	while(scanf("%d",&val) != EOF)
	v.push_back(val);
	LIS(v);
	return 0;
}
