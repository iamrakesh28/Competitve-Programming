#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)

using namespace std;

const int N = 1001;
char maze[N][N];
bool visit[N][N];
int dist[N][N];
int dy[] = {1,0,0,-1};
int dx[] = {0,-1,1,0};
void BFS(int si,int sj,int n,int m) {
	queue <pair <int,int>> q;
	dist[si][sj] = 0;
	visit[si][sj] = true;
	q.push(mk(si,sj));
	pair <int,int> p;
	int x,y;
	while(!q.empty()) {
		p = q.front();
		q.pop();
		y = p.first, x = p.second;
		for(int i=0;i<4;++i) {
			if(y + dy[i] < n && y + dy[i] >= 0 && x + dx[i] >= 0 && x + dx[i] < m) {
				if(visit[y+dy[i]][x+dx[i]] == false) {
					dist[y+dy[i]][x+dx[i]] = dist[y][x] + 1;
					visit[y+dy[i]][x+dx[i]] = true;
					q.push(mk(y+dy[i],x+dx[i]));
				}
			}
		}
	}
}
int main() {
	int n,m,k,si,sj;
	scanf("%d%d%d",&n,&m,&k);
	memset(visit,false,sizeof visit);
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			scanf(" %c",maze[i]+j);
			if(maze[i][j] == '*')
			visit[i][j] = true;
			else if(maze[i][j] == 'X')
			si = i,sj = j;
		}
	}
	if(k % 2) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	BFS(si,sj,n,m);
	string s = "";
	int y=si,x=sj;
	for(int i=1;i<=k;++i) {
		for(int d=0;d<4;++d) {
			if(y + dy[d] < n && y + dy[d] >= 0 && x + dx[d] >= 0 && x + dx[d] < m) {
				if(dist[y+dy[d]][x+dx[d]] <= k-i && maze[y+dy[d]][x+dx[d]] != '*') {
					y += dy[d];
					x += dx[d];
					switch(d) {
						case 0 : s += 'D' ; break;
						case 1 : s += 'L' ; break;
						case 2 : s += 'R' ; break;
						default: s += 'U' ;
					}
					break;
				}
			}
		}
	}
	if(s.length() != k)
	printf("IMPOSSIBLE\n");
	else
	cout<<s<<endl;
	return 0;
}
