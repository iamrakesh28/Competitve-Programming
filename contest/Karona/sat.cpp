#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;
const int maxn = 100010;

int days[1001][1001];
int vis[1001][1001];
int path[1001][1001];
int seen[1001][1001];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    cin >> n >> m;

    vector <string> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ii src, tar;
    queue <ii> q;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            days[i][j] = vis[i][j] = INF;
            path[i][j] = -1;
            seen[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                src = {i, j};
            } else if (a[i][j] == 'T') {
                tar = {i, j};
            } else if (a[i][j] == '*') {
                q.push ({i, j});
                days[i][j] = 0;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        ii c = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = c.first + dr[k];
            int ty = c.second + dc[k];
            if (tx >= 0 and ty >= 0 and tx < n and ty < m and a[tx][ty] == '.') {
                if (days[tx][ty] > days[c.first][c.second] + 1) {
                    days[tx][ty] = days[c.first][c.second] + 1;
                    q.push ({tx, ty});
                }
            }
        }
    }

    q.push (src);
    vis[src.first][src.second] = 0;

    while (!q.empty()) {
        ii c = q.front(); q.pop();
        if (c == tar) {
            break;
        }

        for (int k = 0; k < 4; k++) {
            int tx = c.first + dr[k];
            int ty = c.second + dc[k];
            if (tx >= 0 and ty >= 0 and tx < n and ty < m and (a[tx][ty] == '.' or a[tx][ty] == 'T')) {
                if (vis[tx][ty] > vis[c.first][c.second] + 1 and days[tx][ty] > vis[c.first][c.second] + 1) {
                    vis[tx][ty] = vis[c.first][c.second] + 1;
                    path[tx][ty] = k;
                    q.push ({tx, ty});
                }
            }
        }
    }

    if (vis[tar.first][tar.second] == INF) {
        cout << -1 << "\n";
    } else {
        ii c = tar;
        vector <ii> ans;
        ans.push_back (c);

        while (c != src) {
            int k = path[c.first][c.second];
            c.first -= dr[k];
            c.second -= dc[k];
            ans.push_back (c);
        }
        reverse (ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto el: ans) cout << el.first + 1 << " " << el.second + 1 << "\n";

    }




}
