#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e3 + 5, inf = 1e9;

char board[N][N];
pair <int, int> row[10][N], col[10][N];
pair <int, int> arow[10], acol[10];
int ans[10];

void preproc(int n) {

  for (int i = 0; i < 10; ++i) {
    arow[i] = {inf, -1};
    acol[i] = {inf, -1};
  }
  
  for (int i = 0; i < n; ++i)
    for (int d = 0; d < 10; ++d) {
      row[d][i] = {inf, -1};
      col[d][i] = {inf, -1};
    }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int digit = board[i][j] - '0';

      arow[digit].first = min(j, arow[digit].first);
      arow[digit].second = max(j, arow[digit].second);

      acol[digit].first = min(i, acol[digit].first);
      acol[digit].second = max(i, acol[digit].second);
      
      row[digit][i].first = min(j, row[digit][i].first);
      row[digit][i].second = max(j, row[digit][i].second);

      col[digit][j].first = min(i, col[digit][j].first);
      col[digit][j].second = max(i, col[digit][j].second);
    }
}

void solve(int n, int digit) {
  ans[digit] = 0;
  for (int i = 0; i < n; ++i) {
    if (row[digit][i].second == -1)
      continue;
    int temp;
    int base = row[digit][i].second - row[digit][i].first;
    temp = base * max(i, n - i - 1);
    ans[digit] = max(ans[digit], temp);

    if (acol[digit].second == -1)
      continue;

    base = max(row[digit][i].second, n - row[digit][i].first - 1);
    temp = base * max(acol[digit].second - i, i - acol[digit].first);
    ans[digit] = max(ans[digit], temp);
  }

  for (int i = 0; i < n; ++i) {
    if (col[digit][i].second == -1)
      continue;
    int temp;
    int base = col[digit][i].second - col[digit][i].first;
    temp = base * max(i, n - i - 1);
    ans[digit] = max(ans[digit], temp);

    if (arow[digit].second == -1)
      continue;

    base = max(col[digit][i].second, n - col[digit][i].first - 1);
    temp = base * max(arow[digit].second - i, i - arow[digit].first);
    ans[digit] = max(ans[digit], temp);
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%s", board[i]);
    preproc(n);
    for (int d = 0; d < 10; ++d)
      solve(n, d);
    for (int i = 0; i < 10; ++i)
      printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
