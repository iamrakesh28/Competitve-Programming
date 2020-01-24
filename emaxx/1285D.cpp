#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5;
int a[N], mark[N], node[1 << 21], val;
bool visit[N];

int solve(int j, int n) {
  int Min = 1e9, Max = -1;
  for (int i = 0; i < n; ++i) {
    if (visit[i] == false)
      continue;
    Min = min(Min, mark[i]);
    Max = max(Max, mark[i]);
    if (a[i] & (1 << j)) {
      mark[i] = 2 * mark[i] + 2;
      node[mark[i]]++;
    }
    else {
      mark[i] = 2 * mark[i] + 1;
      node[mark[i]]++;
    }
  }
  bool found = false;
  //cout<<Min<<" "<<Max<<endl;
  for (int i = Min; i <= Max; ++i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    if (node[left] == 0) {
      found = true;
      val = right;
      break;
    }
    if (node[right] == 0) {
      found = true;
      val = left;
      break;
    }
  }
  if (found)
    return j;
  return solve(j - 1, n);
}

int main() {
  int n, x, ind = 30, prev = 30;
  val = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i), visit[i] = true;
  x = 0;
  while (ind >= 0) {
    ind = solve(ind, n);
    for (int i = 0; i < n; ++i)
      if (mark[i] == val) {
	// x = x | (a[i] & (1 << ind));
	if (prev == ind) {
	  int one = a[i] & (1 << ind);
	  x = x | one;
	}
	else {
	  int one = 1 << prev;
	  one--;
	  one = one & (~a[i]);
	  one = one >> (1 + ind);
	  one = one << (1 + ind);
	  one = one | (a[i] & (1 << ind));
	  x = x | one;
	  //visit[i] = true;
	}
	visit[i] = true;
      }
      else
	visit[i] = false;
    memset(mark, 0, sizeof(int) * n);
    memset(node, 0, sizeof node);
    prev = ind;
    ind--;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, a[i] ^ x);
  printf("%d\n", ans);
  return 0;
}
