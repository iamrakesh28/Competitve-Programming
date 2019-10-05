#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

list <int> *adj;
int *dfs_num,*dfs_low,*par,counter,root,point;
bool *visited,*arti;

void addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

int min(int a,int b)
{
	return a < b ? a: b;
}
void ArtPoint(int node)
{
	visited[node] = true;
	//cout<<node+1<<" "<<par[node]+1<<endl;
	dfs_num[node] = dfs_low[node] = counter++;
	for(auto it = adj[node].begin(); it != adj[node].end(); ++it)
	{
		if(visited[*it] == false)
		{
			par[*it] = node;
			if(node == 0)
			root++;
			ArtPoint(*it);
			//equality for the root of the cycle
			if(dfs_low[*it] >= dfs_num[node])
			arti[node] = true;
			dfs_low[node] = min(dfs_low[node],dfs_low[*it]);	
			
		}
		else if(*it != par[node])
		dfs_low[node] = min(dfs_low[node],dfs_num[*it]);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		adj = new list <int> [n];
		dfs_num = new int[n];
		dfs_low = new int[n];
		visited = new bool[n];
		par = new int[n];
		arti = new bool[n];
		par[0] = 0;
		memset(visited,false,sizeof(bool)*n);
		memset(arti,false,sizeof(bool)*n);
		int u;
		counter = 0;
		point = 0;
		root = 0;
		scanf("%d",&u);
		while(u)
		{
			int v=0;
			char ch = getchar_unlocked();	
			while((ch = getchar_unlocked()) && ch != '\n')
			{
				if(ch == ' ')
				{
					if(v)
					{
						addEdge(u-1,v-1);
						//cout<<v<<endl;
						v = 0;
					}
				}
				else
				v = v*10 + ch - '0';
			}
			addEdge(u-1,v-1);
			scanf("%d",&u);
		}
		ArtPoint(0);
		arti[0] = (root > 1);
		for(int i=0;i<n;++i)
		{
			if(arti[i] == true)
			point++;
		}
		printf("%d\n",point);
		scanf("%d",&n);
		delete [] arti,visited,adj,par,dfs_num,dfs_low;
	}
	return 0;
}
