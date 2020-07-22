#include <iostream>
#include <algorithm>
#include <cassert>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
const ll inf = 1e9 + 9;
int a[N];
/*
bool solve(int n, ll temp) {
  ll cur = temp;
  int ind = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > temp) {
      ind = i - 1;
      break;
    }
  }
  if (ind < 0)
    return false;
  for (int i = ind; i < n; ++i) {
    if (temp < a[i])
      return false;
    temp = a[i];
    temp = temp << 1;
  }
  return true;
}*/

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, cnt = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    sort(a, a + n);
    if (x >= a[n - 1]) {
      printf("%d\n", n);
      continue;
    }
    ll temp = x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ll half = temp >> 1;
      if (temp >= a[i]) {
	if (half >= a[i])
	  ans++;// saved for later
	else {
	  ans++;
	  temp = a[i]; //delivered now
	  temp = temp << 1;
	}
      }
      else {
	while (temp < a[i]) {
	  temp = temp << 1;
	  ans++;
	}
	if (temp >= a[n - 1]) {
	  ans = ans + n - i;
	  break;
	}
	ans++;
	temp = a[i];
	temp = temp << 1;
      }
      //cout<<temp<<"=";
    }
    assert(ans > 0);
    printf("%d\n", ans);
  }
  return 0;
}