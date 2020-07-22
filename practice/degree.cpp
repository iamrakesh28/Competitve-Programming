#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e6 + 5;
int pref[N], z[N << 1];

void zfunction(string s) {
  int n = s.length();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, rs;
  cin>>s;
  rs = s;
  reverse(rs.begin(), rs.end());
  zfunction(s + rs);
  int n = s.length();
  long long ans = 0;
  pref[0] = 1;
  for (int i = 2 * n - 2; i >= n; i--) {
    int len = 2 * n - i;
    if (z[i] >= len)
      pref[len - 1] = pref[(len >> 1) - 1] + 1;
    else
      pref[len - 1] = 0;
    ans = ans + pref[len - 1];
  }
  ans++;
  cout<<ans<<endl;
  return 0;
}
