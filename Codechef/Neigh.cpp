
#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}

class Graph{
	public:
	int V;
	list <int> *adjNode;
	void addEdge(int,int);
	Graph(int);
	void Solve(int ,bool *,long int *,int,int,vector <long int> &);
};
Graph::Graph(int v)
{
	this->V =v;
	adjNode = new list <int> [V];
}
void Graph::addEdge(int u,int v)
{
	adjNode[u].pb(v);
	adjNode[v].pb(u);
}
void Graph::Solve(int node,bool *visited,long int *arr,int edge,int d,vector <long int> &v)
{
	visited[node] = true;
	if(edge > d)
	{
		visited[node] = false;
		return ;
	}
	//printf("%ld ",arr[node]);
	v.pb(arr[node]);
	list <int> :: iterator it;
	for(it = adjNode[node].begin();it != adjNode[node].end();++it)
	{	
		if(visited[*it] == false)
		{
			Solve(*it,visited,arr,edge+1,d,v);
		}
	}
	visited[node] = false;
}

int main()
{
	int n,q;
	scanf("%d",&n);
	long int *arr = new long int[n];
	bool *visited = new bool[n];
	for(int i=0;i<n;++i)
	{	
		scanf("%ld",arr+i);
		visited[i] = false;
	}
	Graph Path(n); 
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		Path.addEdge(u-1,v-1);
	}
	scanf("%d",&q);
	while(q--)
	{
		vector<long int> v;
		int u,d,k,size;
		scanf("%d%d%d",&u,&d,&k);
		Path.Solve(u-1,visited,arr,0,d,v);
		size = v.size();
		/*for(int i=0;i<n;++i)
		{	
			visited[i] = false;
		}*/
		if(size < k)
		{
			printf("-1\n");
			continue;
		}
		sort(v.begin(),v.end());
		printf("%ld \n",v[k-1]);
	}
	return 0;
}
