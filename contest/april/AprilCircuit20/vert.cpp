#include <iostream>

typedef long long ll;
using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    ll n, k, len, start, cur = 2;
    scanf("%lld%lld", &n, &k);
    len = n;
    start = ((k << 1) % n) + 1;
    start = start % n;
    while (n > 1) {
      n = n >> 1;
      //cout<<n<<" ";
      start = start + (cur >> 1);
      start = start % len;
      cur = cur << 1;
      //cout<<start+1<<" "<<cur<<endl;
    }
    printf("%lld\n", start + 1);
  }
  return 0;
}
