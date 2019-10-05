#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int dist[50][50], dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
bool visit[50][50];
char maze[50][51];
map <pair<int, int>, int> mp;
list <pair<int, int>> adj[2500];

void bfs(int i, int j, int n, int m) {

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			visit[i][j] = false;
	dist[i][j] = 0;
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = true;
	while (!q.empty()) {
		
		auto p = q.front();
		q.pop();	
		int r = p.first, c = p.second;
		for (int d = 0; d < 4; ++d) {
			int r1 = dr[d] + r, c1 = dc[d] + c;
			if (visit[r1][c1] == true || maze[r1][c1] == '#')
				continue;
			dist[r1][c1] = dist[r][c] + 1;
			q.push(make_pair(r1, c1));
			visit[r1][c1] = true;
		}
	}
}

int prim(int n) {
	
	bool visit[n];
	int dist[n];
	for (int i = 0; i < n; ++i) {
		visit[i] = false;
		dist[i] = inf;
	}
	int sum = 0;
	set <pair <int, int>> q;	
	q.insert(make_pair(0, 0));
	dist[0] = 0;
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(*q.begin());
		int u = p.second;
		visit[u] = true;
		sum += dist[u];
		for (auto it : adj[u]) {
			if (visit[it.second] == true)
				continue;
			if (dist[it.second] == inf) {
				dist[it.second] = it.first;
				q.insert(make_pair(it.first, it.second));
			}
			else if (dist[it.second] > it.first) {
				q.erase(q.find(make_pair(dist[it.second], it.second)));
				dist[it.second] = it.first;
				q.insert(make_pair(it.first, it.second));
			}
		}
	}
	return sum;
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, cnt = 0;
		scanf("%d%d", &m, &n);
		mp.clear();
		vector <pair <int, int>> V;
		for (int i = 0; i < n; ++i) {
			char c = getchar();
			scanf("%[^\n]s", maze[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m && maze[i][j] != '\0'; ++j) {
				if (maze[i][j] == 'A' || maze[i][j] == 'S') {
					V.push_back(make_pair(i, j));
					mp[{i, j}] = cnt++;
				}
			}
		}
		for (auto it = V.begin(); it != V.end(); ++it) {	
			int u = mp.at(*it), v, i = (*it).first, j = (*it).second;
			bfs(i, j, n, m);
			for (auto to = V.begin(); to != V.end(); ++to) {
				if ((*to).first == i && (*to).second == j)
					continue;
				v = mp.at(*to);
				//cout<<u<<" "<<v<<" "<<(*to).first<<" "<<(*to).second<<endl;
				adj[u].push_back(make_pair(dist[(*to).first][(*to).second], v));
			}
		}
		n = cnt;
		if (n == 0)
			printf("0\n");
		else
			printf("%d\n", prim(n));
		for (int i = 0; i < n; ++i)
			adj[i].clear();
	}	
	return 0;
}
