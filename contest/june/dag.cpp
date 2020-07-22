/*
Competitive Programming Style code.

Search for DAG DP to get more understanding of this code.
*/

#include <iostream>
#include <cstring>
#include <list>
#include <vector>

using namespace std;

/*
N -> maximum number of vertices in the graph. 
adj[N] -> adjacency list. It stores {weight, vertiex} in the list.
visit[N] -> visit[u] stores  whether u vertex is visited or not (true means visited and false means unvisited).
pointer[N] -> pointer[u] stores the vertex number of child in having longest path. It is used for retrieving the longest path.
outdeg[N] -> outdeg[u] stores the out degree of vertex u.
dp[N] -> dp[u] stores the longest path length for vertex u.
 */

const int N = 1e5 + 5;
list <pair<int, int>> adj[N];  // {weight, node}
bool visit[N];
int dp[N], pointer[N], outdeg[N];

// dfs call in vertex u.
void dfs(int u) {
  // path will store the longest path from the current vertex u.
  // child stores the vertex that will give the longest path starting from vertex u.
  int path = 0, child = -1;
  // marks vertex u as visited.
  visit[u] = true;
  for (auto v : adj[u]) {
    int val;
    // if not visited, then call dfs and find dp[v].
    if (visit[v.second] == false)
      dfs(v.second);
    val = dp[v.second];
    // if the weight edge u -> v + longest path from vertex v is greater than or equal to current path valu, then update both the values (path adn child).
    if (val + v.first >= path) {
      path = val + v.first;
      child = v.second;
    }
  }

  // stores longest path length from vertex u. In case of sink vertex, path will be zero.
  dp[u] = path;
  // stores the next vertex that will give the longest path starting from vertex u.
  // In case of sink vertex, it will be -1.
  pointer[u] = child;
  return;
}

int main() {

  // n -> number of vertices in the graph.
  // Vertices are numbered from 1 to n in the input while in the program it is from 0 to n - 1
  // m -> number of directed edges.
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    // edge u -> v and weight w of the edge u -> v.
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    // just for making vertices numbered from 0 to n - 1.
    u--, v--;
    outdeg[v]++;
    // pushes {weight, vertex} in the adjacency list of vertex u.
    adj[u].push_back({w, v});
  }
  int longest = -1, top;
  // marks every vertices to not visited.
  memset(visit, false, sizeof visit);
  /*
  for (int i = 0; i < n; ++i)
    if (outdeg[i] == 0) {
      top = i;
      break;
    }
  */
  // this problem has just one source (vertex 1) and one sink(vertex n).
  top = 0;
  // find longest path from vertex 1.
  dfs(top);
  // path stores the sequences of vertices in the longest path.
  vector <int> path;
  longest = dp[top];
  // starting vertex in the path is vertex top (1).
  path.push_back(top);
  // v is the next vertex
  int v = pointer[top];
  // while we do not reach the sink
  while (v != -1) {
    path.push_back(v);
    v = pointer[v];
  }
  // prints the path length and the path
  printf("%d\n", longest);
  for (int v : path)
    printf("%d ", v + 1);
  puts("");
  return 0;
}
