#include<iostream>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

const int N = 405;
const long long INF = static_cast<long long>(1e17);

int nInp, S, m1, m2, m3;
long long g, h, d[N], p[N], safe[N];

// s: n - 1
// t: n - 2
int n, s, t;
long long res[N][N];
vector<vector<int> > a;

inline int secVert(int u) {return nInp + u;}

void read_and_initialize() {
    cin >> nInp;

    n = 2 * nInp + 2; // 2 for each vert and 1 for super source, and 1 for super sink
    s = n - 2;
    t = n - 1;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            res[i][j] = 0;
    }
    memset(d, 0, sizeof(int) * n);
    for(int i = 0;i < nInp;i++)
        cin >> d[i];
    for(int i = 0;i < nInp;i++)
        cin >> p[i];

    cin >> S;
    for(int i = 0;i < S;i++)
        cin >> safe[i];

    cin >> m1;
    for(int i = 0;i < m1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        res[secVert(u)][v] += w;
    }

    cin >> m2 >> g;
    for(int i = 0;i < m2;i++) {
        int u, v, w;
        cin >> u >> v;
        res[secVert(u)][v] += g;
    }

    cin >> m3 >> h;
    for(int i = 0;i < m3;i++) {
        int u, v, w;
        cin >> u >> v;
        res[secVert(u)][v] += h;
    }
    for(int i = 0;i < nInp;i++)  {  // multi-source
	res[s][i] = d[i];
    }
    // Max Flow given to ith vert is the number of people living there

    for(int i = 0;i < S;i++)        // multi-sink
        res[safe[i]][t] = INF;
    // important: connect 1st vertex of safe[i] and not second
    // since we arrive at a safe vertex and are NOT passing
    // through it

    for(int i = 0;i < nInp;i++)     // vertex capacity split
        res[i][i + nInp] = p[i];

    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(res[i][j] > 0) {
                a[i].push_back(j);
                //if(res[i][j] == 0)
                    a[j].push_back(i);
            }
        }
    }
}

/*
int pred[N];
bool visited[N];

long long augmentPath(int v, long long currMin) {
    if(v == s)
        return currMin;

    long long minEdge = augmentPath(pred[v], min(currMin, res[pred[v]][v]));
    res[pred[v]][v] -= minEdge;
    res[v][pred[v]] += minEdge;
    
    return minEdge;
}

// returns true if found path, else false
bool BFS() {
    for(int i = 0;i < n;i++) {
        pred[i] = -1;
        visited[i] = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        if(u == t)
            return true;

        for(int v : a[u]) {
            if(res[u][v] > 0 && !visited[v]) {
                pred[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return false;
}
*/

typedef long long ll;

ll bfs(vector <int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue <pair <int, ll>> q;
  q.push({s, INF});
  while (!q.empty()) {
    int cur = q.front().first;
    ll flow = q.front().second;
    q.pop();

    for (int next : a[cur]) {
      if (parent[next] == -1 && res[cur][next]) {
	parent[next] = cur;
	ll new_flow = min(flow, res[cur][next]);
	if (next == t)
	  return new_flow;
	q.push({next, new_flow});
      }
    }
  }
  return 0;
}

long long EdmondsKarp() {
   ll flow = 0;
  vector <int> parent(n);
  ll new_flow;
  while (new_flow = bfs(parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      res[prev][cur] -= new_flow;
      res[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}

void solve() {
    long long sum_val = 0;
    
    for(int i = 0;i < n;i++)
        sum_val += d[i];
 
    long long numSaved = EdmondsKarp();
    if(numSaved >= sum_val)
        cout << "All Safe\n";
    else
        cout << numSaved << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        read_and_initialize();
        solve();
    }

    return 0;
}
