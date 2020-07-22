#include <iostream>

using namespace std;

typedef long long ll;

ll find1(ll n, int trail) {
  ll ans;
  ans = n >> (trail + 1);
  if (n & (1LL << trail))
    ans++;
  return ans;
}

ll find2(ll n, int trail) {
  ll ans, val = n;
  ans = n >> (trail + 1);
  n = n >> trail;
  n = n | 1LL;
  n = n << trail;
  if (n < val)
    ans++;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, ans = 0;
    cin>>n;
    for (int i = 1; i <= 62; ++i) {
      ll val = find1(n, i);
      //cout<<val<<" "<<i<<endl;
      ans = ans + val * (i + 1);
    }
    for (int i = 1; i <= 62; ++i) {
      ll val = find2(n, i);
      //cout<<val<<" "<<i<<endl;
      ans = ans + val;
    }
    ans++;
    cout<<ans<<endl;
  }
  return 0;
}
