#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
pair <int, int> seg[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      int si, ei;
      scanf("%d%d", &si, &ei);
      seg[i] = {si, ei};
    }
    sort(seg, seg + n);
    int ans = 0, end = 0;
    for (int i = 0; i < n; ++i) {
      if (end - 1 < seg[i].first) {
	end = seg[i].first + k;
	ans++;
      }
      if (seg[i].second <= end)
	continue;
      int times = seg[i].second - end;
      if (times % k)
	times = times / k + 1;
      else
	times = times / k;
      end = end + times * k;
      ans += times;
    }
    printf("Case #%d: %d\n", q + 1, ans);
  }
  return 0;
}
