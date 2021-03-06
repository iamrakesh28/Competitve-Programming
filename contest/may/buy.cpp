#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>

typedef long long ll;

using namespace std;

const int N = 1e3 + 5;
string A, B, S[N * 10];
ll lef[N], righ[N];
int bi[N * 10];
map <string, int> mp;

void precomp(int n) {
  int a = A.length(), b = B.length();
  memset(lef, 0, sizeof lef);
  memset(righ, 0, sizeof righ);
  for (int i = 0; i < n; ++i) {
    int len = S[i].length();
    if (len > a)
      continue;
    string s = "";
    for (int j = 0; j < len; ++j)
      s += A[j];
    if (s == S[i])
      lef[len - 1] += bi[i];
    for (int j = 1; j + len <= a; ++j) {
      s.erase(s.begin());
      s += A[j + len - 1];
      if (s == S[i])
	lef[j + len - 1] += bi[i];
    }
  }

  for (int i = 1; i < a; ++i)
    lef[i] += lef[i - 1];

  for (int i = 0; i < n; ++i) {
    int len = S[i].length();
    if (len > b)
      continue;
    string s = "";
    for (int j = 0; j < len; ++j)
      s = B[b - j - 1] + s;
    if (s == S[i])
      righ[b - len] += bi[i];
    for (int j = b - 2; j - len + 1 >= 0; --j) {
      s.erase(s.end() - 1);
      s = B[j - len + 1] + s;
      if (s == S[i])
	righ[j - len + 1] += bi[i];
    }
  }

  for (int i = b - 2; i >= 0; i--)
    righ[i] += righ[i + 1];

}

ll solve() {
  ll ans = 0, temp;
  int a = A.length(), b = B.length();
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j) {
      temp = lef[i] + righ[j];
      for (int k = 2; k <= 26; ++k) {
	string s = "";
	int l, r;
	l = min(i, max(0, i - k + 2));
	r = j + k - 1 - (i - l + 1);
	if (r >= b)
	  continue;
	for (int m = l; m <= i; ++m)
	  s += A[m];
	for (int m = j; m <= r; ++m)
	  s += B[m];
	if (mp.find(s) != mp.end())
	  temp += mp.at(s);
	for (int m = l + 1, c = r + 1; m <= i && c < b; ++m, ++c) {
	  s.erase(s.begin());
	  s += B[c];
	  if (mp.find(s) != mp.end())
	    temp += mp.at(s);
	}
      }
      ans = max(ans, temp);
    }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>A>>B>>n;
    mp.clear();
    for (int i = 0; i < n; ++i) {
      cin>>S[i]>>bi[i];
      mp.insert({S[i], bi[i]});
    }
    precomp(n);
    ll ans = solve();
    cout<<ans<<endl;
  }
  return 0;
}
