#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;
int arr[N], st[N][18],  Q[N];
long long ret[N];
vector <int> query;

void update(int r, int g) {
  auto it = lower_bound(query.begin(), query.end(), g);
  if (it == query.end() || *it != g)
    return;
  ret[it - query.begin()] += r;
  return;
}

int main() {

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", arr + i), st[i][0] = arr[i];
  for (int i = 1; i < 18; ++i)
    for (int j = 0; j + (1 << i) <= n; ++j)
      st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", Q + i);
    query.push_back(Q[i]);
  }
  sort(query.begin(), query.end());
  query.erase(unique(query.begin(), query.end()), query.end());
  for (int i = 0; i < n; ++i) {
    int cur = i, g = st[i][0];
    while (true) {
      if (g == 1) {
	update(n - cur, g);
	break;
      }
      int nxt = cur + 1;
      for (int i = 17; i >= 0; i--)
	if (nxt + (1 << i) <= n && st[nxt][i] % g == 0)
	  nxt = nxt + (1 << i);
      // cout<<g<<endl;
      update(nxt - cur, g);
      if (nxt < n)
	g = __gcd(g, st[nxt][0]);
      else
	break;
      cur = nxt;
    }
  }
  for (int i = 0; i < q; ++i) {
    auto it = lower_bound(query.begin(), query.end(), Q[i]);
    printf("%lld\n", ret[it - query.begin()]);
  }
  return 0;
}
