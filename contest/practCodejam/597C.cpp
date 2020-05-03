#include <iostream>

typedef long long ll;

using namespace std;

const int N = 1e5, K = 11;
ll bit[K][N];
int n, k;

ll sum(int x, int y) {
  ll ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
      ret += bit[i][j];
  return ret;
}

void update(int x, int y, ll delta) {
  for (int i = x; i <= k; i = i | (i + 1))
    for (int j = y; j < n; j = j | (j + 1))
      bit[i][j] += delta;
}

int main() {
  ll ans;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ll temp;
    update(0, a - 1, 1);
    for (int j = 1; j <= k; ++j) {
      temp = sum(j - 1, a - 2) - sum(j - 2, a - 2);
      //cout<<temp<<endl;
      update(j, a - 1, temp);
    }
  }
  ans = sum(k, n - 1) - sum(k - 1, n - 1);
  printf("%lld\n", ans);
  return 0;
}
