#include <bits/stdc++.h>

using namespace std;

void reverse(int i,int j,string &a)
{
	int n=j-i+1;
	for(int k=0;k<n/2;++k)
	swap(a[k+i],a[n-k-1+i]);
	return ;
}
int BFS(string a,string b)
{
	int cnt=0;
	queue <string> q;
	q.push(a);
	map <string,int> mp;
	mp.insert({a,cnt++});
	vector <int> cost;
	cost.push_back(0);
	if(a.compare(b) == 0)
	return cost[mp.at(a)];
	while(!q.empty())
	{
		string p = q.front();
		q.pop();
		//cout<<p<<endl;
		if(p.compare(b) == 0)
		return cost[mp.at(p)];
		for(int i=0;i<9;++i)
		{
			for(int j=i+1;j<10;++j)
			{
				string s=p; 
				reverse(i,j,s);	
				//cout<<s<<endl;	
				if(mp.count(s) == 0)
				{
					mp.insert({s,cnt++});
					cost.push_back(cost[mp.at(p)]+1);
					q.push(s);
				}
			}
		}
	}
	return -1;
}
int main()
{
	string a,b;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while((cin>>a>>b) && a != "*" && b != "*")
	{
		//cout<<a<<" "<<b<<endl;
		cout<<BFS(a,b)<<endl;
	}
	return 0;
}
