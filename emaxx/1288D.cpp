#include <iostream>

using namespace std;

const int N = 3e5;
int a[N][8];
pair <int, int> ans[1 << 8];
bool bit[1 << 8];

bool solve(int n, int m, int x) {
  bool poss = false;
  for (int i = 0; i < (1 << m); ++i)
    bit[i] = false;
  for (int i = 0; i < n; ++i) {
    int num = 0;
    for (int j = 0; j < m; ++j)
      if (a[i][j] >= x)
	num = num | (1 << j);
    bit[num] = true;
    ans[num] = {i, i};
  }
  //if (x)
  //cout<<ans[1].first<<endl;
  int num = (1 << m) - 1;
  for (int i = 0; i < (1 << m); ++i) {
    if (bit[i] == false)
      continue;
    for (int j = i; j < (1 << m); ++j)
      if (bit[j]) {
	if ((i | j) == num) {
	  poss = true;
	  ans[i | j] = {ans[i].first , ans[j].first};
	}
	//cout<<x<<" "<<i<<" "<<j<<" "<<num<<" "<<(i | j)<<endl;
      }
    if (poss)
      break;
  }
  return poss;
}

int main() {
  int n, m, Max = -1, u = 0, v = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", a[i] + j), Max = max(Max, a[i][j]);
  int beg = 0, end = Max, mid;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    if (solve(n, m, mid)) {
      beg = mid + 1;
      //cout<<mid<<endl;
      u = ans[(1 << m) - 1].first, v = ans[(1 << m) - 1].second;
    }
    else
      end = mid - 1;
  }
  printf("%d %d\n", u + 1, v + 1);
  return 0;
}
