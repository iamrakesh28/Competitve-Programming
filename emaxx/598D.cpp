#include <bits/stdc++.h>

using namespace std;

char mus[1000][1001];
int ans[1000][1000];
bool visit[1000][1000];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void bfs(int n, int m, int i, int j) {
	
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	int sum = 0;
	vector <pair <int, int>> cell;
	visit[i][j] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int r = p.first, c = p.second;
		cell.push_back(make_pair(r, c));
		for (int d = 0; d < 4; ++d) {
			if (visit[dx[d] + r][dy[d] + c] == true)
				continue;
			if (mus[dx[d] + r][dy[d] + c] == '.') {
				q.push(make_pair(dx[d] + r, dy[d] + c));
				visit[dx[d] + r][dy[d] + c] = true;
				continue;
			}
			sum++;
		}
	}
	for (auto it : cell)
		ans[it.first][it.second] = sum;
}

int main() {
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s", mus[i]);
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			visit[i][j] = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visit[i][j] == false && mus[i][j] == '.')
				bfs(n, m, i, j);
				//cout<<ans[1][1]<<endl;
		}
	}
	for (int i = 0; i < k; ++i) {
		int r, c;
		scanf("%d%d", &r, &c);
		printf("%d\n", ans[r - 1][c - 1]);
	}
	return 0;
}
