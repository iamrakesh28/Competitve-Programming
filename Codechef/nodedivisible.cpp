#include <bits/stdc++.h>

using namespace std;

void max(vector <int> & possible,int n)
{
	int swap;
	for(int i=0;i<2;++i)
	{
		for(int j=n-1;j>i;--j)
		{
			if(possible[j]>possible[j-1])
			{
				swap=possible[j];
				possible[j]=possible[j-1];
				possible[j-1]=swap;
			}
		}
	}
}

int maximum(int a, int b)
{
	if(a>b)
	return a;
	return b;
}

class Graph
{
	int V;
	bool *visited;
	list <int> *adj;
	public :
	Graph(int ,bool *);
	void addEdge(int,int );
	int DFS(int,int,int *,int *);

};

Graph::Graph(int V,bool *pt)
{
	this->V=V;
	adj= new list <int> [V];
	visited=pt;
}

void Graph::addEdge(int v, int w)
{
	adj[w].push_back(v);
	adj[v].push_back(w);
}

int Graph::DFS(int node,int k,int *arr,int *ans)
{
	/*if(adj[node].empty())
	{
		//printf("yes");
		if(arr[node]%k==0)
		return 1;
		return 0;
	}*/
	visited[node]=true;
	list <int> :: iterator i;
	vector <int> possible;
	int path=0;
	for(i=adj[node].begin();i!=adj[node].end();++i)
	{
		if(visited[*i]==false)
		possible.push_back(DFS(*i,k,arr,ans));	
	}
	max(possible,possible.size());
	if(possible.size()>0)
	{
		if(arr[node]%k==0)
		{
			path=possible[0]+1;
			if(possible.size()>1)
			*ans=maximum(*ans,path+possible[1]);
			else
			*ans=maximum(*ans,path);
		}
		else
		{
			*ans=maximum(*ans,possible[0]);
		}
	}
	else
	{
		if(arr[node]%k==0)
		return 1;
		return 0;
	}	
	return path;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int *arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",arr+i);
	}
	int v,w,path,ans=1;
	bool *visited = (bool*)malloc(sizeof(bool)*n);
	memset(visited,false,sizeof(visited));
	Graph tree(n,visited);
	for(int i=0;i<n-1;++i)
	{
		scanf("%d%d",&v,&w);
		tree.addEdge(v-1,w-1);	
	}
	path=tree.DFS(0,k,arr,&ans);
	printf("%d\n",ans-1);
	return 0;
}
