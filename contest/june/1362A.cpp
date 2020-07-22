#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll a, b, ans = 0, rem;
    cin>>a>>b;
    if (a >= b) {
      if (a % b) {
	puts("-1");
	continue;
      }
      rem = a / b;
    }
    else {
      if (b % a) {
	puts("-1");
	continue;
      }
      rem = b / a;
    }
    int cnt = 0;
    while (rem % 2 == 0) {
      rem = rem / 2;
      cnt += 1;
    }
    if (rem > 1) {
      puts("-1");
      continue;
    }
    ans = ans + cnt / 3;
    cnt  = cnt % 3;
    ans = ans + cnt / 2;
    cnt  = cnt % 2;
    ans = ans + cnt;
    cout<<ans<<endl;
  }
  return 0;
}
