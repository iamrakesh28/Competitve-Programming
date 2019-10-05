#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

//typedef pair <int,int> pair <int,int>;

class Graph{

	public :
	int V;
	list <int> *adj;
	vector <pair <int,int>> *small;
	int *nodes;
	void addEdge(int,int);
	Graph(int);
	void DFS(int,int,int*);
	int DFSUtil(long int,long int);
};

Graph :: Graph(int v)
{
	this->V = v;
	adj = new list <int> [v];
	small = new vector <pair <int,int>>[v];
	nodes = new int[v];
	memset(nodes,0,sizeof(int)*v);
}
bool compare(pair <int,int> &a,pair <int,int> &b)
{
	if(a.first < b.first)
	return true;
	else if(a.first > b.first)
	return false;
	return (a.second < b.second);
}

void Graph::addEdge(int u,int v)
{
	nodes[u]++;
	nodes[v]++;
	adj[u].pb(v);
	adj[v].pb(u);
}
void Graph::DFS(int node,int comp,int *visited)
{
	visited[node] = comp;
	small[comp].push_back(make_pair(nodes[node],node));
	list <int> :: iterator it;
	for(it = adj[node].begin();it != adj[node].end();++it)
	{
		if(visited[*it] == -1)
		DFS(*it,comp,visited);
	}
	return;
}
int Graph::DFSUtil(long int a,long int b)
{
	int count=0;
	int *visited = new int[V];
	vector <pair <int,int>> :: iterator it;
	memset(visited,-1,sizeof(int)*V);
	int comp=0;
	for(int i=0;i<V;++i)
	{
		if(visited[i] == -1)
		{
			DFS(i,comp,visited);
			sort(small[comp].begin(),small[comp].end(),compare);
			comp++;
		}
	}
	for(int i=0;i<V;++i)
	{
		int min,max,reg;
		reg = visited[i];
		if(nodes[i] == 0)
		continue;
		it = small[reg].begin();
		/*if((*it).second == i)
		{
			it++;
			min = (*it).first;
			it--;
		} 
		else
		min = (*it).first;
		it = small[reg].end();
		it--;
		if((*it).second == i)
		{
			it--;
			max = (*it).first;
			it++;
		} 
		else
		max = (*it).first;*/
		min = (*it).first;
		it = small[reg].end();
		it--;
		max = (*it).first;
		long int l = a*min;
		long int r = b*max;
		if(l < nodes[i] && nodes[i] < r)
		count++;
	}
	delete [] nodes;
	delete [] adj;
	delete [] small,visited;
	return count;
}
int main()
{
	int n,m;
	long int a,b;
	scanf("%d%d%ld%ld",&n,&m,&a,&b);
	Graph special(n);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		special.addEdge(u-1,v-1);
	}
	int result = special.DFSUtil(a,b);
	printf("%d\n",result);
	return 0;
}
