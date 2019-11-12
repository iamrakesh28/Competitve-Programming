#include <bits/stdc++.h>

#define N 100005
using namespace std;

map <string,int> mp;
vector <int> word[10000000];
int photo[N],n,num,vert[N];
bool visit[N];
int main()
{
	scanf("%d",&n);
	int v=0,cnt=0;
	num = 0;
	for(int i=0;i<n;++i)
	{
		char c;
		int m;
		scanf(" %c%d",&c,&m);
		if(c == 'H')
		{
			photo[i] = 0;
			cnt++;
		}
		else
		{
			photo[i] = 1;
			vert[v++] = i;
		}
		string p;
		for(int j=0;j<m;++j)
		{
			cin>>p;
			if(mp.count(p) == 0)
			{
				mp.insert({p,num});
				word[num].push_back(i);
				num++;
			}
			else
			word[mp.at(p)].push_back(i);
		}
	}
	memset(visit,false,sizeof visit);
	cout<<cnt+v/2<<endl;
	vector<vector<int>> V(cnt+v/2);
	int i,j,k;
	for(i=0,j=0,k=-1;i<num;i++)
	{
		for(auto it=word[i].begin();it!=word[i].end();++it)
		{
			if(visit[*it] == false)
			{
				if(photo[*it] == 0)
				{
					V[j++].push_back(*it);
					visit[*it] = true;
				}
				else
				{
					if(k < 0)
					{
						k = j;
						j++;
					}
					else if(V[k].size()==2)
					{
						k = j;
						j++;
					}
					V[k].push_back(*it);
					//cout<<V[k].size()<<"-";
					visit[*it] = true;
				}
			}
		}
	}
	for(int i=0;i<j;++i)	
	{
		for(auto it=V[i].begin();it!=V[i].end();++it)
		cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}
