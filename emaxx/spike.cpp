#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

#define INF 10000000
#define mk(x,y) make_pair(x,y)
using namespace std;
typedef pair <int,int> ipair;

char maze[40][40];
int n,m,k,dist[40][40];

bool BFS(int r,int c) {
	set <pair<int,ipair>> q;
	q.insert(mk(0,mk(r,c)));
	dist[r][c] = 0;
	int i,j;
	while(!q.empty()) {
		auto p = q.begin();
		q.erase(p);
		i = (*p).second.first, j = (*p).second.second;
		if(i >= 1 && maze[i-1][j] != '#') {
			int c = (maze[i-1][j] == 's' ? 1:0);
			if(dist[i-1][j] == INF) {
				dist[i-1][j] = dist[i][j] + c;
				q.insert(mk(dist[i-1][j],mk(i-1,j)));
			}
			else if(dist[i-1][j] > dist[i][j] + c) {
				q.erase(q.find(mk(dist[i-1][j],mk(i-1,j))));
				dist[i-1][j] = dist[i][j] + c;
				q.insert(mk(dist[i-1][j],mk(i-1,j)));
			}
		}
		if(i < n-1 && maze[i+1][j] != '#') {
			int c = (maze[i+1][j] == 's' ? 1:0);
			if(dist[i+1][j] == INF) {
				dist[i+1][j] = dist[i][j] + c;
				q.insert(mk(dist[i+1][j],mk(i+1,j)));
			}
			else if(dist[i+1][j] > dist[i][j] + c) {
				q.erase(q.find(mk(dist[i+1][j],mk(i+1,j))));
				dist[i+1][j] = dist[i][j] + c;
				q.insert(mk(dist[i+1][j],mk(i+1,j)));
			}
		}
		if(j >= 1 && maze[i][j-1] != '#') {
			int c = (maze[i][j-1] == 's' ? 1:0);
			if(dist[i][j-1] == INF) {
				dist[i][j-1] = dist[i][j] + c;
				q.insert(mk(dist[i][j-1],mk(i,j-1)));
			}
			else if(dist[i][j-1] > dist[i][j] + c) {
				q.erase(q.find(mk(dist[i][j-1],mk(i,j-1))));
				dist[i][j-1] = dist[i][j] + c;
				q.insert(mk(dist[i][j-1],mk(i,j-1)));
			}
		}
		if(j < m-1 && maze[i][j+1] != '#') {
			int c = (maze[i][j+1] == 's' ? 1:0);
			if(dist[i][j+1] == INF) {
				dist[i][j+1] = dist[i][j] + c;
				q.insert(mk(dist[i][j+1],mk(i,j+1)));
			}
			else if(dist[i][j+1] > dist[i][j] + c) {
				q.erase(q.find(mk(dist[i][j+1],mk(i,j+1))));
				dist[i][j+1] = dist[i][j] + c;
				q.insert(mk(dist[i][j+1],mk(i,j+1)));
			}
		}
	}
	vector <int> V;
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			//cout<<dist[i][j]<<" ";
			if(maze[i][j] == '@')
				V.push_back(dist[i][j]);
		}
	}
	sort(V.begin(),V.end());
	if(V[0]*2 <= k)
	return true;
	return false;
}
int main()
{
	int r,c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			scanf(" %c",maze[i]+j);	
			if(maze[i][j] == 'x')
			r = i,c = j;
			dist[i][j] = INF;
		}
	}
	if(BFS(r,c))
	printf("SUCCESS\n");
	else
	printf("IMPOSSIBLE\n");
	return 0;
}
