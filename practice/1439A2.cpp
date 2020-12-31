#include <iostream>
#include <vector>

using namespace std;

const int N = 105;
char table[N][N];
vector <pair <int, int>> ans;

void push(
          pair <int, int> p1,
          pair <int, int> p2,
          pair <int, int> p3) {

  ans.push_back(p1);
  ans.push_back(p2);
  ans.push_back(p3);  

  return;
}

void opern(vector <pair <int, int>> val[]) {

  if (val[0].size() == 4)
    return;
  
  if (val[0].size() == 1) {
    push(val[1][0], val[1][1], val[1][2]);
    return;
  }

  if (val[0].size() == 2) {
    push(val[0][0], val[0][1], val[1][0]);
    push(val[0][0], val[0][1], val[1][1]);
    return;
  }

  if (val[0].size() == 3) {
    push(val[0][0], val[0][1], val[1][0]);

    // (1, 0), (0, 2) -> 0
    push(val[0][2], val[1][0], val[0][1]);

    // (0, 1) -> 0
    push(val[0][0], val[1][0], val[0][2]);
    return;
  }

  push(val[1][0], val[1][1], val[1][2]);

  // 1, 3 -> 1
  push(val[1][0], val[1][1], val[1][3]);

  // (1, 3), (1, 2) -> 0
  push(val[1][3], val[1][2], val[1][1]);

  // (1, 1) -> 0
  push(val[1][0], val[1][2], val[1][3]);
  
}

void solve(int n, int m) {

  vector <pair <int, int>> val[2];
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {

      val[0].clear();
      val[1].clear();
      
      val[table[i][j] - '0'].push_back({i, j});
      val[table[i][j + 1] - '0'].push_back({i, j + 1});
      val[table[i + 1][j] - '0'].push_back({i + 1, j});
      val[table[i + 1][j + 1] - '0'].push_back({i + 1, j + 1});

      opern(val);
    }
  }
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);

    ans.clear();
    for (int i = 0; i < n; ++i)
      scanf("%s", table[i]);

    if ((n & 1) && (m & 1) && table[n - 1][m - 1] != '0') {
      table[n - 1][m - 1] = '0';
      table[n - 2][m - 1] = '1' - table[n - 2][m - 1] + '0';
      table[n - 2][m - 2] = '1' - table[n - 2][m - 2] + '0';

      push({n - 1, m - 1}, {n - 2, m - 1}, {n - 2, m - 2});
    }

    if (m & 1) {
      int row = n >> 1;
      row = row << 1;

      for (int i = 0; i < row; i += 2) {

        int cnt = 0;
        
        if (table[i][m - 1] == '1') {
          cnt++;
          ans.push_back({i, m - 1});
        }
        if (table[i + 1][m - 1] == '1') {
          cnt++;
          ans.push_back({i + 1, m - 1});
        }

        if (cnt == 1) {
          ans.push_back({i, m - 2});
          ans.push_back({i + 1, m - 2});

          table[i][m - 2] = '1' - table[i][m - 2] + '0';
          table[i + 1][m - 2] = '1' - table[i + 1][m - 2] + '0';
        }
        else if (cnt == 2) {
          ans.push_back({i + 1, m - 2});
          table[i + 1][m - 2] = '1' - table[i + 1][m - 2] + '0';
        }
        
        table[i][m - 1] = table[i + 1][m - 1] = '0';
      }
    }

    if (n & 1) {
      int col = m >> 1;
      col = col << 1;

      for (int i = 0; i < col; i += 2) {

        int cnt = 0;
        
        if (table[n - 1][i] == '1') {
          cnt++;
          ans.push_back({n - 1, i});
        }
        if (table[n - 1][i + 1] == '1') {
          cnt++;
          ans.push_back({n - 1, i + 1});
        }

        if (cnt == 1) {
          ans.push_back({n - 2, i});
          ans.push_back({n - 2, i + 1});

          table[n - 2][i] = '1' - table[n - 2][i] + '0';
          table[n - 2][i + 1] = '1' - table[n - 2][i + 1] + '0';
        }
        else if (cnt == 2) {
          ans.push_back({n - 2, i});
          table[n - 2][i] = '1' - table[n - 2][i] + '0';
        }
        
        table[n - 1][i] = table[n - 1][i + 1] = '0';
      }
    }
    
    if (n & 1)
      n--;
    if (m & 1)
      m--;

    solve(n, m);

    printf("%d\n", ans.size() / 3);
    for (int i = 0; i < ans.size(); i += 3) {
      printf("%d %d ", ans[i].first + 1, ans[i].second + 1);
      printf("%d %d ", ans[i + 1].first + 1, ans[i + 1].second + 1);
      printf("%d %d ", ans[i + 2].first + 1, ans[i + 2].second + 1);
      puts("");
    }
  }
  
  return 0;
}
