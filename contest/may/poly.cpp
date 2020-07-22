#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 26;
bool adj[N][N], pres[N];
int visit[N];
char S[35][35];
stack <int> order;
bool cycle = false;

void dfs(int u) {
  visit[u] = 0;
  for (int i = 0; i < N; ++i) {
    if (adj[u][i] == false)
      continue;
    if (visit[i] == 0) {
      cycle = true;
      return;
    }
    if (visit[i] == 1)
      continue;
    // cout<<char(i+'A')<<endl;
    dfs(i);
  }
  visit[u] = 1;
  order.push(u);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int r, c;
    cycle = false;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i)
      scanf("%s", S[i]);
    for (int i = 0; i < N; ++i) {
      visit[i] = -1;
      pres[i] = false;
    }
    memset(adj, false, sizeof adj);
    for (int i = 0; i < r; ++i)
      for (int k = 0; k < c; ++k)
	pres[S[i][k] - 'A'] = true;
    for (int i = 0; i < r - 1; ++i)
      for (int k = 0; k < c; ++k)
	if (S[i][k] != S[i + 1][k])
	  adj[S[i][k] - 'A'][S[i + 1][k] - 'A'] = true;
    for (int i = 0; i < N; ++i) 
      if (visit[i] == -1 && pres[i]) {
	dfs(i);
      }
    printf("Case #%d: ", j + 1);
    if (cycle) {
      puts("-1");
      while (order.size())
	order.pop();
      continue;
    }
    vector <int> ans;
    while (order.size()) {
      char c = order.top() + 'A';
      order.pop();
      ans.push_back(c);
    }
    reverse(ans.begin(), ans.end());
    for (auto ch : ans)
      putchar(ch);
    puts("");
  }
  return 0;
}
