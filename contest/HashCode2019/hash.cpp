#include <bits/stdc++.h>

#define N 100005
using namespace std;

map <string,int> mp[N];
vector <string> word[N];
int photo[N],n,pref[N],dp[N],vert[N];
int simi(int i,int j)
{
	int cmn=0,tagi,tagj;
	for(auto it=word[i].begin();it!=word[i].end();++it)
	{
		if(mp[j].count(*it))
		cmn++;
	}
	tagi = word[i].size()-cmn;
	tagj = word[j].size()-cmn;
	return min(cmn,min(tagi,tagj));
}

int ans(int i)
{
	if(photo[i] == 1)
	return 0;
	if(dp[i] == -1)
	{
		dp[i] = 0;
		for(int k=i+1;k<n;++k)
		{
			int sim = ans(k)+simi(i,k);
			if(dp[i] < sim)
			{
				dp[i] = sim;
				pref[i] = k;
			}
		}
	}
	return dp[i];
}
int main()
{
	scanf("%d",&n);
	int v=0;
	for(int i=0;i<n;++i)
	{
		char c;
		int m;
		scanf(" %c%d",&c,&m);
		if(c == 'H')
		photo[i] = 0;
		else
		{
			photo[i] = 1;
			vert[v++] = i;
		}
		string p;
		for(int j=0;j<m;++j)
		{
			cin>>p;
			//if(mp[i].count() == 0)
			mp[i].insert({p,j});
			word[i].push_back(p);
			//cout<<p<<endl;
		}
	}
	memset(dp,-1,sizeof dp);
	memset(pref,-1,sizeof pref);
	int ind , val = 0;
	for(int i=0;i<n;++i)
	{
		int num = ans(i);
		if(val < num)
		{
			ind = i;
			val = num;
		}
	}
	//cout<<v<<endl;
	int cnt=0;
	for(int i=ind;i!=-1;i=pref[i])
	cnt++;
	cout<<cnt+v/2<<endl;
	for(int i=ind;i!=-1;i=pref[i])
	cout<<i<<endl;
	for(int i=0;i<v;i+=2)
	cout<<vert[i]<<" "<<vert[i+1]<<endl;
	return 0;
}
