#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

class Graph{
	public:
	int V;
	list <int> *adj;
	void addEdge(int,int);
	Graph(int);
	void BFS(int);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list <int> [V];
}
void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void Graph:: BFS(int root)
{
	bool *visited = new bool [V];
	memset(visited,false,sizeof(visited));
	visited[root] = true;
	queue <int> q;
	q.push(root);
	list <int> :: iterator it;
	vector <int> dist(V,-1);
	dist[root] = 0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(it = adj[p].begin();it!= adj[p].end();++it)
		{
			if(visited[*it] == false)
			{
				visited[*it] = true;
				q.push(*it);
				dist[*it] = dist[p] + 6;
			}
		}
	} 
	for(int i=0;i<V;++i)
	{
		if(i != root)
		printf("%d ",dist[i]);
	}
	printf("\n");
}
 
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		Graph graph(n);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			graph.addEdge(u-1,v-1);
		}
		int s;
		scanf("%d",&s);
		graph.BFS(s-1);
	}
	return 0;
}
