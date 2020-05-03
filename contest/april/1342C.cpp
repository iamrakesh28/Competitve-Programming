#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

vector <int> p;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, q, d, cnt = 0;
    scanf("%d%d%d", &a, &b, &q);
    p.clear();
    d = a * b;
    p.resize(d + 1);
    p[0] = 0;
    for (int i = 0; i < d; ++i) {
      int v1 = (i % a) % b, v2 = (i % b) % a;
      if (v1 != v2)
	cnt++;
      p[i + 1] = cnt;
    }

    //cout<<cnt<<" "<<d<<endl;
    while (q--) {
      ll l, r, ans = 0, r1, l1;
      scanf("%lld%lld", &l, &r);
      l1 = l / d + 1;
      r1 = r / d;
      if (r1 < l1) {
	l1 = l % d;
	r1 = r % d;
	ans = p[r1 + 1] - p[l1];
	printf("%lld ", ans);
	continue;
      }
      ans = (r1 - l1) * cnt;
      l = l % d;
      r = r % d;
      ans += p[d] - p[l];
      ans += p[r + 1];
      printf("%lld ", ans);
    }
    puts("");
  }
  return 0;
}
