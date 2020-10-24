#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
ll a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    ll high = 0, low = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
      if (a[i] > 0)
	high += a[i];
      else
	low -= a[i];
    }
    //cout << low << " " << high << endl;
    ll ans, h = 0, carr = 0;
    for (int i = 0; i < n; ++i) {
      if (low == 0)
	break;
      if (a[i] <= 0) {
	//cout << carr << " ";
	if (-a[i] >= carr) {
	  a[i] += carr;
	  carr = 0;
	  //cout << a[i] << " " << carr << " ";
	  //cout << a[i] << " ";
	}
	else {
	  carr += a[i];
	  a[i] = 0;
	}
	low += a[i];
	//cout << " " << low << " " << high << endl;
	continue;
      }
      
      ll temp = min(low, a[i]);
      carr += temp;
      low = low - temp;
      high = high - temp;
      //cout << low << " " << high << endl;
    }
    ans = high;
    printf("%lld\n", ans);
  }
  return 0;
}
