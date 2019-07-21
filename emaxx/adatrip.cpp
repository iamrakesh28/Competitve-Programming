#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define INF 100000000

using namespace std;

typedef pair <int,int> ipair; 

list <ipair> adj[500000];
void addEdge(int u,int v,int w)
{
	adj[u].pb(mk(w,v));
	adj[v].pb(mk(w,u));
}

void Dijkstra(int s,int n)
{
	list <int> B[n*10+1];
	vector<pair<int, list<int> :: iterator>> dist(n);
	for(int i=0;i<n;++i)
		dist[i].first = INF;
	dist[s].first = 0;
	B[0].pb(s);
	//dist[s].second = B[0].begin();
	int idx=0,a=0,b=1;
	while(true)
	{
		while(B[idx].size() == 0 && idx < 10*n)
			idx++;	
		if(idx == 10*n)
			break;
		if(a != idx) {
			a = idx;
			b = B[idx].size();
		}
		int u = B[idx].front();
		B[idx].pop_front();
		for(auto it=adj[u].begin();it != adj[u].end();++it)
		{
			int v = (*it).second;
			int w = (*it).first;
			int du = dist[u].first;
			int dv = dist[v].first;
			if(dv > du + w)
			{
				if(dv != INF)
				B[dv].erase(dist[v].second);
				dist[v].first = du + w;
				dv = dist[v].first;
				B[dv].push_front(v);
				dist[v].second = B[dv].begin();
			}
		}
	}
	printf("%d %d\n",a,b);
	//for(int i=0;i<n;++i)
		//cout<<dist[i].first<<" ";
	//cout<<endl;
}

int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addEdge(x,y,w);
	}
	while(q--)
	{
		int qi;
		scanf("%d",&qi);
		Dijkstra(qi,n);
	}
	return 0;
}
