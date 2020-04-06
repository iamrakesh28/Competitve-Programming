#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 505;
bool adj[N][N], visit[N];
stack <int> st;
int a[N][N], ans[N];
vector <int> mat[N];

void dfs(int u, int n) {
  visit[u] = true;
  for (int v = 0; v < n; ++v) {
    if (visit[v] == false && adj[u][v] && adj[v][u] == false)
      dfs(v, n); 
  }
  st.push(u);
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d%d", &n, &k);
    while (st.size())
      st.pop();
    for (int i = 0; i < n; ++i) {
      visit[i] = false;
      mat[i].clear();
      for (int j = 0; j < n; ++j)
	adj[i][j] = false;
    }
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < n; ++j)
	scanf("%d", a[i] + j);
      for (int r = 0; r < n - 1; ++r)
	for (int c = r + 1; c < n; ++c)
	  adj[a[i][r] - 1][a[i][c] - 1] = true;
    }
    for (int i = 0; i < k; ++i)
      if (visit[a[i][0] - 1] == false)
	dfs(a[i][0] - 1, n);
    int node = 1, temp = 1, prev = st.top(), level = 0;
    ans[prev] = 0;
    while (st.size()) {
      int cur = st.top();
      st.pop();
      if (adj[prev][cur] && adj[cur][prev]) {
	ans[prev] = 0;
	if (temp)
	  mat[level].push_back(prev);
	else
	  mat[++level].push_back(prev);
	temp++;
      }
      else {
	ans[prev] = cur + 1;
	node = max(node, temp);
	temp = 0;
      }
    }
    temp = max(node, temp);
    for (int i = 0; i < node; ++i) {
      prev = -1;
      for (int j = 0; j <= level; ++j) {
	if (mat[j].size() <= i)
	  continue;
	if (prev != -1)
	  ans[prev] = mat[j][i] + 1;
	prev = mat[j][i];  
      }
    }
    printf("%d\n", node);
    for (int i = 0; i < n; ++i)
      printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
