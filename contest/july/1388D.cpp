#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], dep[N];
bool visit[N];
vector <int> vec, adj[N], ret[N];
ll ans, dp[N];

void dfs(int u) {
  dp[u] = 0;
  visit[u] = true;
  for (int v : adj[u]) {
    if (visit[v] == false)
      dfs(v);
    if (dp[v] >= 0) {
      dp[u] += dp[v];
      ret[u].push_back(v);
    }
    else
      dep[v] = u;
  }
  dp[u] += a[u];
}

void dfs2(int u) {
  visit[u] = true;
  for (int v : ret[u]) {
    //cout<<u+1<<" "<<v+1<<endl;
    if (visit[v] == false) {
      dfs2(v);
      //cout<<v+1<<"==";
      //vec.push_back(v);
    }
  }
  //cout<<u+1<<"==";
  vec.push_back(u);
}

int main() {
  int n;
  scanf("%d", &n);
  ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    visit[i] = false;
    dep[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
    if (b[i] != -1)
      adj[b[i] - 1].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (visit[i] == false) 
      dfs(i);
    ans += dp[i];
  }

  for (int i = 0; i < n; ++i)
    visit[i] = false;
  
  for (int i = 0; i < n; ++i)
    if (dep[i] == -1 && visit[i] == false)
      dfs2(i);
  
  for (int i = 0; i < n; ++i)
    if (dep[i] != -1) {
      if (visit[dep[i]] == false)
	dfs2(dep[i]);
      //cout<<i+1<<"=="<<dep[i]+1<<endl;
      if (visit[i] == false) {
	vec.push_back(i);
	visit[i] = true;
      }
    }
  printf("%lld\n", ans);
  for (int v : vec)
    printf("%d ", v + 1);
  puts("");
  return 0;
}
