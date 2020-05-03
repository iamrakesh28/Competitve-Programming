#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e4;
int bit[N], n, ans[N];

int sum(int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1)
    res += bit[x];
  return res;
}

void update(int x, int delta) {
  for (; x < n; x = x | (x + 1))
    bit[x] += delta;
}

void init() {
  memset(bit, 0, sizeof(int) * n);
  memset(ans, 0, sizeof(int) * n);
  for (int i = 0; i < n; ++i)
    update(i, 1);
}

int find(int beg, int end, int rem) {
  int mid, ans = -1;
  while (beg <= end) {
    mid = beg + end >> 1;
    int s = sum(mid);
    if (s == rem) {
      ans = mid;
      end = mid - 1;
    }
    else if (s < rem)
      beg = mid + 1;
    else
      end = mid - 1;
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int cur = 0;
    scanf("%d", &n);
    init();
    for (int i = 2; i <= n; ++i) {
      int sum1, ind, tot = sum(n - 1), rem, sum2 = sum(cur - 1);
      sum1 = tot - sum2;
      rem = i % tot;
      if (sum1 >= rem) {
	if (rem)
	  ind = find(cur, n - 1, rem + sum2);
	else {
	  if (sum1 == tot)
	    ind = find(cur, n - 1, tot);
	  else
	    ind = find(0, n - 1, sum2);
	}
	ans[ind] = i - 1;
      }
      else {
	rem = rem - sum1;
	ind = find(0, n - 1, rem);
	ans[ind] = i - 1;
      }
      //cout<<ind<<":"<<i-1<<" "<<rem<<" "<<cur<<"\n";
      update(ind, -1);
      ind = ind + 1 % n;
      sum2 = sum(n - 1) - sum(ind - 1);
      if (sum2 < 1)
	ind = 0;
      cur = find(0, n - 1, 1 + sum(ind - 1));
    }
    for (int i = 0; i < n; ++i) {
      if (ans[i])
	printf("%d ", ans[i]);
      else
	printf("%d ", n);
    }
    puts("");
  }
  return 0;
}
