#include <iostream>
#include <queue>
#include <set>
#include <cassert>

using namespace std;

const int N = 51, INF = 2e9;
pair <int, int> matrix[N][N], par[N][N];
char mask[N][N + 1], ans[N][N + 1]; 
bool visit[N][N];
int dist[N][N][N][N];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int cost[4];

bool valid(int i, int j, int n) {

    if (i >= 0 && j >= 0 && i < n && j < n)
        return true;
    return false;
}

void initialize(int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visit[i][j] = false;
        }
    }
    
    return;
}

char direction(pair <int, int> &a, pair <int, int> &b) {

    int dy = b.first - a.first;
    if (dy != 0) {
        if (dy < 0)
            return 'U';
        else
            return 'D';
    }

    int dx = b.second - a.second;
    if (dx > 0)
        return 'R';
    else
        return 'L';
}

bool shortest_cycle(pair <int, int> a, pair <int, int> b, int n) {

    if (valid(b.first, b.second, n) == false)
        return false;

    int i = a.first, j = a.second, r = b.first, c = b.second;
    if (mask[r][c] == '.' && ans[r][c] == '.') {
        ans[i][j] = direction(a, b);
        ans[r][c] = direction(b, a);

        return true;
    }
    else
        return false;
}

bool spanning_tree(int i, int j, int n) {

    visit[i][j] = true;
    dist[i][j][i][j] = 0;
    set <pair <int, pair <int, int>>> s;
    s.insert({0, {i, j}});

    while (s.size()) {
        auto it = s.begin();
        int r = (*it).second.first, c = (*it).second.second;
        visit[r][c] = true;
        s.erase(it);

        // cout << r + 1 << " " << c + 1 << endl;

        pair <int, int> cur = {r, c};

        if (i != r || j != c)
            ans[r][c] = direction(cur, par[r][c]);
        
        for (int d = 0; d < 4; ++d) {
            int row = dr[d] + r, col = dc[d] + c, w = cost[d];
            if (valid(row, col, n) == false || visit[row][col] == true)
                continue;
            if (mask[row][col] == '.' || matrix[row][col] != make_pair(i, j))
                continue;
            if (dist[i][j][row][col] >= INF) {
                s.insert({w, {row, col}});
                par[row][col] = {r, c};
            }
            else if (dist[i][j][row][col] > w) {
                s.erase(s.find({dist[i][j][row][col], {row, col}}));
                dist[i][j][row][col] = w;
                s.insert({w, {row, col}});
                par[row][col] = {r, c};
            }
        }
    }

    bool poss = true;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (matrix[r][c] == make_pair(i, j) && visit[r][c] == false) {
                poss = false;
                break;
            }
        }
        if (poss == false)
            break;
    }
    
    return poss;
}

bool find_next(int n, pair <int, int> &pt) {

    int min_cnt = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0;

            if (mask[i][j] == '#')
                continue;
            if (ans[i][j] != '.')
                continue;

            for (int d = 0; d < 4; ++d) {
                int r = i + dr[d], c = j + dc[d];
                if (valid(r, c, n) && mask[r][c] == '.' && ans[r][c] == '.')
                    cnt++;
            }

            if (cnt < min_cnt) {
                min_cnt = cnt;
                pt = {i, j};
            }
        }
    }

    if (min_cnt >= INF)
        return false;
    return true;
}

int main() {

    int n;
    scanf("%d", &n);

    int pu, pl, pd, pr;
    scanf("%d%d%d%d", &pu, &pl, &pd, &pr);
    cost[0] = pd;
    cost[1] = pu;
    cost[2] = pr;
    cost[3] = pl;
    
    initialize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mask[i][j] = '#';
            ans[i][j] = '.';
        }
    }
        
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int xi, yi;
            scanf("%d%d", &xi, &yi);
            matrix[i][j] = {xi - 1, yi - 1};
            mask[xi - 1][yi - 1] = '.';
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mask[i][j] == '.')
                cnt = (cnt + 1) % 2;
        }
    }

    if (cnt) {
        puts("-1");
        return 0;
    }
    
    bool poss = true;
    pair <int, int> pt;
    while (find_next(n, pt)) {
        int i = pt.first, j = pt.second;
        // cout << i + 1 << " " << j + 1 << endl;
        for (int d = 0; d < 4; ++d) {
            poss = shortest_cycle({i, j}, {i + dr[d], j + dc[d]}, n);
            if (poss)
                break;
        }
        
        if (poss == false) {
            puts("-1");
            return 0;
        }
    }

    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                for (int l = 0; l < n; ++l)
                    dist[i][j][k][l] = INF;

    initialize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pair <int, int> pt = matrix[i][j];
            if (visit[pt.first][pt.second] == false)
                poss = spanning_tree(pt.first, pt.second, n);
            if (poss == false)
                break;
        }
        if (poss == false)
            break;
    }

    if (poss == false) {
        puts("-1");
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            switch (ans[i][j]) {
            case 'U' : sum += pu; break;
            case 'D' : sum += pd; break;
            case 'L' : sum += pl; break;
            default : sum += pr;
            }
        }
    }

    printf("%d\n", sum);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            putchar(ans[i][j]);
        }
        puts("");;
    }
    return 0;
}
