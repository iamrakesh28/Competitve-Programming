#include <bits/stdc++.h>

using namespace std;
bool fits(vector <int> &a, vector <int> &b)
{
	for(int i=0;i<a.size();++i)
	{
		if(a[i] >= b[i])
		return false;
	}
	return true;
}

list <int> *adj;
bool *visited;
void DFS(int u, vector <int> &len,vector <int> &prev)
{
	visited[u] = true;
	for(auto it = adj[u].begin();it != adj[u].end();++it)
	{
		if(visited[*it] == false)
		DFS(*it,len,prev);
		if(len[u] < len[*it] + 1)
		{
			len[u] = len[*it]+1;
			prev[u] = *it;
		}
	}
	return;
}
void LIS(int k,int n)
{
	vector <int> len(k,1);
	vector <int> prev(k,-1);
	for(int i=0;i<k;++i)
	{
		if(visited[i] == false)
		DFS(i,len,prev);
	}
	int maxm = 0,id;
	vector <int> seq;
	for(int i=0;i<k;++i)
	{
		if(maxm < len[i])
		{
			maxm = len[i];
			id = i;
		}
	} 
	for(int i=id;i>=0;i=prev[i])
	seq.push_back(i+1);
	printf("%d\n",maxm);
	for(int i=0;i<maxm-1;++i)
	printf("%d ",seq[maxm-i-1]);
	printf("%d\n",seq[0]);
}
int main()
{
	int n,k;
	while(scanf("%d%d",&k,&n) != EOF)
	{
		vector < vector <int> > box(k);
		adj = new list <int> [k]; 
		visited = new bool[k];
		memset(visited,false,sizeof(bool)*k);
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<n;++j)
			{
				int dim;
				scanf("%d",&dim);
				box[i].push_back(dim);
			}
			sort(box[i].begin(),box[i].end());
		}
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<k;++j)
			{
				if(fits(box[j],box[i]))
				adj[i].push_back(j);
			}
		}
		LIS(k,n);
		delete [] adj,visited;
	}
	return 0;
}
