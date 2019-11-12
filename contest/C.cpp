#include <bits/stdc++.h>

#define N 100005
using namespace std;

list <int> adj[N];
int ci[N],cnt=0;
bool visit[N],brek[N];

void dfs(int u)
{
	visit[u] = true;
	bool f;
	//cout<<u+1<<endl;
	if(ci[u] == 1)
		f = true;
	else
		f = false;
	for(auto it : adj[u]) {
		if(!visit[it]) {
			dfs(it);
			if(ci[it] == 1)
			f = f && true;
			else
			f = false;
		}
	}
	brek[u] = f;
	if(f == true)
		cnt++;
	return ;
}

int main()
{
	int n,root;
	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		int p,c;
		scanf("%d%d",&p,ci+i); 
		if(p != -1) {
			adj[p-1].push_back(i);
		}
		else
			root = i;
		visit[i] = false;
		brek[i] = false;
	}
	dfs(root);
	if(!cnt) {
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;++i)
		if(brek[i])
			printf("%d ",i+1);
	printf("\n");
	return 0;
}
