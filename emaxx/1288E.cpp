#include <iostream>

using namespace std;

const int N = 3e5;
pair <int, int> ans[N];
int prev[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    ans[i].first = {i + 1, i + 1};
    prev[i] = -1;
  }
  for (int i = 0; i < m; ++i) {
    int msg;
    scanf("%d", &msg);
    if (prev[msg - 1] == -1) {
      ans[msg - 1].first = 1;
      ans[msg - 1].second = ans[msg - 1].second + i;
      prev[msg - 1] = i;
    }
    else {
      ans[msg - 1].second = max(ans[msg - 1].second, i - prev[msg - 1]);
      prev[msg - 1] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (prev[i] == -1)
      ans[i].second = ans[i].second
  }
  for (int i = 0; i < n; ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
