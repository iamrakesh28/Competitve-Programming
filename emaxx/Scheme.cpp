#include <bits/stdc++.h>

using namespace std;

list <int> *adj;
int *deg;
bool *visit;
void addEdge(int u,int v)
{
	adj[u].push_back(v);
}

int DFS(int u)
{
	visit[u] = true;
	int next = u;
	for(auto it = adj[u].begin();it != adj[u].end(); ++it) {
		if(visit[*it] == false) {
			next = DFS(*it);
		}
		else
			next = *it;
	}	
	return next;		
}
int main()
{
	int n;
	scanf("%d",&n);
	adj = new list<int> [n];
	deg = new int[n];
	visit = new bool[n];
	for(int i=0;i<n;++i) {
		visit[i] = false;
		deg[i] = 0;
	}
	for(int i=0;i<n;++i) {
		int v;
		scanf("%d",&v);
		addEdge(i,v-1);
		deg[v-1]++;
	}
	int k=0,u,v,cnt=0,x,y;
	vector <pair<int,int>> E;
	for(int i=0;i<n;++i) {
		if(deg[i] == 0) {
			if(k)
			E.push_back(make_pair(u+1,i+1));
			else
				v = i;
			k++;
			u = DFS(i);	
		}
 	}
	for(int i=0;i<n;++i) {
		if(visit[i] == false) {
			if(cnt)
			E.push_back(make_pair(x+1,i+1));
			else
				y = i;
			cnt++;
			x = DFS(i);	
		}
 	}
	if(cnt && k) {
		E.push_back(make_pair(u+1,y+1));
		E.push_back(make_pair(x+1,v+1));	
		k = k + cnt;
	}
	else if(!k && cnt) {
		E.push_back(make_pair(x+1,y+1));	
		if(cnt > 1)
		k = cnt;
		else
		k  =0;
	}
	else if(!cnt && k) {
		E.push_back(make_pair(u+1,v+1));	
	}
	printf("%d\n",k);
	if(k) {
		for(auto it=E.begin();it != E.end(); ++it) {
			printf("%d %d\n",(*it).first,(*it).second);
		}
	}
	return 0;
}
