#include <iostream>
#include <cassert>

using namespace std;

const int N = 5e5, inf = 1e9;

int main() {
  int n;
  scanf("%d", &n);
  assert(n <= N && n >= 1);
cout<<n<<endl;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    assert(l <= r);
    assert(l >= 1 && r <= inf);
  }
  int q;
  scanf("%d", &q);
cout<<q<<endl;
  assert(q <= N);
  for (int i = 0; i < q; ++i) {
    int m;
    scanf("%d", &m);
	cout<<m<<endl;
    sum += m;
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      assert(a >= 1 && a <= inf);
    }
  }
  assert(sum <= N);
  return 0;
}
