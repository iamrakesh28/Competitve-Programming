#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector <pair<int, int>> q;
  scanf("%d", &n);
  int k;
  for (k = 30; k >= 0; k--)
    if (n & (1 << k))
      break;
  
  for (int i = 0; i <= k; ++i) {
    int pw = 1 << i;
    for (int j = 0; j < (1 << k); j += (pw << 1))
      for (int r = 0; r < pw && j + r + pw < (1 << k); ++r)
	q.push_back({j + r, j + r + pw});
  }

  for (int i = 0; i <= k; ++i) {
    int pw = 1 << i;
    for (int j = n - (1 << k); j < n; j += (pw << 1))
      for (int r = 0; r < pw && j + r + pw < n; ++r)
	q.push_back({j + r, j + r + pw});
  }
  printf("%d\n", q.size());
  for (auto v : q)
    printf("%d %d\n", v.first + 1, v.second + 1);
  return 0;
}
