#include <bits/stdc++.h>

#define pb(x) push_back(x)
using namespace std;

class Graph{
	public:
	int V,maxBlack;
	list <int> *adj;
	int *color;
	int *maxColor;
	Graph(int);
	void addEdge(int,int);
	bool isSafe(int);
	void coloring(int,int);
	void copy(void);
};

Graph::Graph(int v)
{
	this->V = v;
	this->maxBlack = 0;
	adj = new list<int> [v];
	color = new int[v];
	maxColor = new int[v];
	memset(maxColor,0,sizeof(int)*v);
	memset(color,0,sizeof(int)*v);
}

void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void Graph::copy(void)
{
	for(int i=0;i<V;++i)
	maxColor[i] = color[i];
}
void Graph::coloring(int u,int black)
{
	if(u == V)
	{
		if(black > maxBlack)
		{
			maxBlack = black;
			copy();
		}
		return;
	}
	color[u] = 1;
	if(isSafe(u))
	coloring(u+1,black+1);
	color[u] = 0;
	coloring(u+1,black);
}

bool Graph::isSafe(int u)
{
	for(auto it = adj[u].begin();it != adj[u].end();++it)
	{
		if(*it == u)
		continue;
		if(color[u] == color[*it])
		return false;
	}
	return true;
}
int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL); */
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int n,k,u,v;
		cin>>n>>k;
		Graph G(n);
		while(k--)
		{
			cin>>u>>v;
			G.addEdge(u-1,v-1);
		}
		G.coloring(0,0);
		printf("%d\n",G.maxBlack);
		int i,cnt=1;
		for(i=0;i<n;++i)
		{
			if(G.maxColor[i] == 1)
			{
				if(cnt < G.maxBlack)
				cout<<i+1<<" ";
				else
				cout<<i+1;
				cnt++;
			}
		}
		cout<<"\n";
	}
	return 0;
}
