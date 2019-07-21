#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

class Graph{
	public:
	int V;
	bool *visited;
	list <int> *adj;
	Graph(int);
	void addEdge(int,int);
	void BFS(int,bool *);
};
Graph::Graph(int v)
{
	this->V = v;
	visited = new bool[V];
	adj = new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
}

void Graph::BFS(int root,bool *mark)
{
	for(int i=0;i<V;++i)
	{
		if(mark[i] ==  false)
		{
			for(int j = i+1; j <= i+6 && j< V; ++j)
			{
				if(mark[j] == true)
				{
					addEdge(i,*(adj[j].begin()));	
				}
				else
				addEdge(i,j);
			}
		}
	}
	memset(visited,false,sizeof(bool)*V);
	queue <int> q; 
	q.push(root);
	vector <int> dist(V,-1);
	dist[root] = 0;
	visited[root] = true;
	list <int> :: iterator it;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(it = adj[p].begin();it!=adj[p].end();++it)
		{
			if(visited[*it] == false)
			{
				visited[*it] = true;
				dist[*it] = dist[p] + 1;
				q.push(*it);
			}

		}
	}
	printf("%d\n",dist[V-1]);
	//delete [] visited;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		Graph ladder(100);
		int n;
		scanf("%d",&n);
		bool *mark = new bool[100];
		memset(mark,false,sizeof(bool)*100);
		for(int i=0;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			ladder.addEdge(u-1,v-1);
			mark[u-1] = true;
		}
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			ladder.addEdge(u-1,v-1);
			mark[u-1] = true;
		}
		ladder.BFS(0,mark);
		//delete [] mark;
	}
	return 0;
}
