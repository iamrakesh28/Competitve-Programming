#include <bits/stdc++.h>

const int N = 1005;
using namespace std;

typedef pair <int, int> ipair;

bool visit[N][N];
char city[N + 1][2 * N + 1];
int dist[N + 1][N + 1], dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int dx[] = {-1, 0, 0, 0}, dy[] = {0, 0, -1, 1};
vector <ipair> vend;


int dfs(int r, int c)
{
	visit[r][c] = true;
	int d = dist[r][c];
	int x = r + 1, y = 2 * c + 1;
	for (int i = 0; i < 4; ++i) {
		if (city[x + dx[i]][y + dy[i]] == '|' || city[x + dx[i]][y + dy[i]] == '_')
			continue;
		if (visit[r + dr[i]][c + dc[i]] == true)
			continue;
		d = max(d, dfs(r + dr[i], c + dc[i]));
	}
	return d;
}

void bfs(int n, int m)
{
	for (int i = 0; i < n; ++i)
		memset(visit + i, false, sizeof(bool) * m);
	queue <ipair> q;
	for (auto it : vend) {
		q.push(it);
		dist[it.first][it.second] = 0;
		visit[it.first][it.second] = true;
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int r = p.first, c = p.second;
		int x = r + 1, y = 2 * c + 1;
		for (int i = 0; i < 4; ++i) {
			if (city[x + dx[i]][y + dy[i]] == '|' || city[x + dx[i]][y + dy[i]] == '_')
				continue;
			if (visit[r + dr[i]][c + dc[i]] == true)
				continue;
			visit[r + dr[i]][c + dc[i]] = true;
			q.push(make_pair(r + dr[i], c + dc[i]));
			dist[r + dr[i]][c + dc[i]] = dist[r][c] + 1;
		}
	}
}

int main()
{
	int n,m, ap, bp, k;
	scanf("%d%d%d%d",&n,&m,&ap,&bp);
	for (int i = 0; i < n + 1; ++i) {
		char ch = getchar();
		scanf("%[^\n]s",city + i);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d",&x, &y);
		vend.push_back(make_pair(x - 1, y - 1));
	}
	bfs(n, m);
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}*/
	for (int i = 0; i < n; ++i)
		memset(visit + i, false, sizeof(bool) * m);
	for (auto it : vend)
		visit[it.first][it.second] = true;
	printf("%d\n",dfs(ap - 1, bp - 1));
	return 0;
}
