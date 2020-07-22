#include <iostream>
#include <set>

using namespace std;

const int N = 2e5 + 5;

int visit[N];
set <int> pre;

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; ++k) {
    int n;
    scanf("%d", &n);
    pre.clear();
    for (int j = 0; j < n; ++j)
      scanf("%d", visit + j);
    int ans = 0;
    if (n == 1) {
      printf("Case #%d: %d\n", k + 1, 1);
	  continue;
    }
    for (int i = 0; i < n; ++i) {
      if (i == n - 1) {
	auto it = pre.end();
	it--;
	if ((*it) < visit[i])
	  ans++;
      }
      else if (i == 0) {
	if (visit[i] > visit[i + 1])
	  ans++;
	pre.insert(visit[i]);
      }
      else  {
	auto it = pre.end();
	it--;
	if ((*it) < visit[i] && visit[i] > visit[i + 1])
	  ans++;
	pre.insert(visit[i]);
      }
    }
    printf("Case #%d: %d\n", k + 1, ans);
  }
  return 0;
}
