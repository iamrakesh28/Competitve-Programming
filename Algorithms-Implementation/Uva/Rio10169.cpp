#include <bits/stdc++.h>

#define SIZE 26
#define pb(x) push_back(x)
#define WHITE -1

using namespace std;

list <int> *adj;
int *dfs_num,*dfs_low,counter=0,point,child;
bool *art;
void addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void Articul(int u,int par)
{
	dfs_num[u] = dfs_low[u] = counter++;
	for(auto it = adj[u].begin();it != adj[u].end();++it)
	{
		if(dfs_num[*it] == WHITE)
		{
			Articul(*it,u);
			if(u == 0)
			child++;
			if(dfs_low[*it] >= dfs_num[u])
			art[u] = true;
			dfs_low[u] = min(dfs_low[u],dfs_low[*it]);
		}
		else if(*it != par)
		dfs_low[u] = min(dfs_low[u],dfs_num[*it]);
	}	
}
bool compar(string &a,string &b)
{
	if(a.compare(b) < 0)
	return true;
	return false;
}
int binary(vector<string> &V,int n,string key)
{
	int begin=0,end = n-1,middle;
	while(begin <= end)
	{
		middle = (begin + end)/2;
		int res = V[middle].compare(key);
		if(res == 0)
		break;
		else if(res > 0)
		end = middle-1;
		else
		begin = middle+1;
	}
	return middle;
}
int main()
{
	int n,i=0;
	while(scanf("%d",&n) && n)
	{
		i++;
		string city;
		vector <string> V;
		for(int i=0;i<n;++i)
		{
			cin>>city;
			V.pb(city);
		}
		int k;
		scanf("%d",&k);
		dfs_num = new int[n];
		dfs_low = new int[n];
		art = new bool[n];
		adj = new list<int>[n];
		memset(dfs_num,WHITE,sizeof(int)*n);	
		memset(art,false,sizeof(bool)*n);
		child = counter = 0;
		sort(V.begin(),V.end(),compar);
		for(int i=0;i<k;++i)
		{
			string city,city2;
			cin>>city>>city2;
			int id1 = binary(V,n,city);
			int id2 = binary(V,n,city2);
			//cout<<id1<<endl<<id2<<endl;
			addEdge(id1,id2);
		}
		for(int i=0;i<n;++i)
		if(dfs_num[i] == WHITE)
		Articul(i,i);
		point = 0;
		art[0] = (child > 1);
		for(int i=0;i<n;++i)
		{
			if(art[i])
			point++;	
		}
		printf("City map #%d: %d camera(s) found\n",i,point);
		for(int i=0;i<n;++i)
		{
			if(art[i])
			cout<<V[i]<<endl;	
		}
		putchar('\n');
		delete [] dfs_num,dfs_low,art,adj;
	}
	return 0;
}
