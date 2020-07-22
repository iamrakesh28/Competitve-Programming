#include <iostream>
#include <vector>

using namespace std;

const int N = 2e3 + 5;
vector <pair <int, int>> pos;
bool dp[N][N];
int p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    pos.clear();
    for (int i = 0; i < 2 * n; ++i)
      scanf("%d", p + i);
    int cur = p[0];
    pos.push_back({0, 0});
    for (int i = 1; i < 2 * n; ++i) {
      if (cur < p[i]) {
	pos[pos.size() - 1].second = i - 1;
	cur = p[i];
	pos.push_back({i, i});
      }
    }
    pos[pos.size() - 1].second = 2 * n - 1;
    int size = pos.size();
    for (int i = 0; i <= size; ++i)
      for (int j = 0; j <= n; ++j) {
	if (i == 0) {
	  dp[i][j] = (j == 0 ? true : false);
	  continue;
	}
	dp[i][j] = dp[i - 1][j];
	int len = pos[i - 1].second - pos[i - 1].first + 1;
	if (j >= len)
	  dp[i][j] = dp[i][j] || dp[i - 1][j - len];
      }
    if (dp[size][n])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
