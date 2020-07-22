#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>

typedef long long ll;

using namespace std;

const int N = 1e3 + 5, m = 1e9 + 9, p = 31;
string A, B, S[N * 10];
ll lef[N], righ[N], power[N];
int bi[N * 10];
unordered_map <string, int> mp;
unordered_map <ll, ll> amap[N];
unordered_map <ll, int> vmap;
vector <pair <ll, int>> vec[N * N];

void precomp(int n) {
  int a = A.length(), b = B.length();
  memset(lef, 0, sizeof lef);
  memset(righ, 0, sizeof righ);
  for (int j = 1; j <= 26; ++j) {
    string s = "";
    if (j > a)
      break;
    for (int i = 0; i < j; ++i)
      s += A[i];
    if (mp.find(s) != mp.end())
      lef[j - 1] += mp.at(s);
    for (int i = 1; i + j <= a; ++i) {
      s.erase(s.begin());
      s += A[i + j - 1];
      if (mp.find(s) != mp.end())
	lef[i + j - 1] += mp.at(s);
    }
  }

  for (int i = 1; i < a; ++i)
    lef[i] += lef[i - 1];

  for (int j = 1; j <= 26; ++j) {
    if (j > b)
      break;
    string s = "";
    for (int i = 0; i < j; ++i)
      s = B[b - i - 1] + s;
    if (mp.find(s) != mp.end())
      righ[b - j] += mp.at(s);
    for (int i = b - 2; i - j + 1 >= 0; --i) {
      s.erase(s.end() - 1);
      s = B[i - j + 1] + s;
      if (mp.find(s) != mp.end())
	righ[i - j + 1] += mp.at(s);
    }
  }

  for (int i = b - 2; i >= 0; i--)
    righ[i] += righ[i + 1];

}

ll solve() {
  ll ans = 0, temp;
  int a = A.length(), b = B.length();
  
  for (int i = 0; i < a; ++i) {
    ll s = 0;
    for (int j = 1; j <= 25; ++j) {
      if (i + j > a)
	break;
      s = (s + (A[i + j - 1] - 'a' + 1) * power[j - 1]) % m;
      if (vmap.find(s) != vmap.end()) {
	int id = vmap.at(s);
	for (auto it : vec[id]) {
	  if (amap[i + j - 1].find(it.first) == amap[i + j - 1].end())
	    amap[i + j - 1].insert(it);
	  else
	    amap[i + j - 1][it.first] += it.second;
	}
      }
    }
  }
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j) {
      ll s = 0;
      temp = lef[i] + righ[j];
      //cout<<i+1<<" "<<j+1<<" ";
      for (int k = 1; k <= 25; ++k) {
	if (j + k > b)
	  break;
	s = (s + (B[j + k - 1] - 'a' + 1) * power[k - 1]) % m;
	//cout<<s<<" ";
	if (amap[i].find(s) != amap[i].end()) {
	  temp += amap[i].at(s);
	  //cout<<s<<" ";
	}
      }
      //cout<<temp<<endl;
      ans = max(ans, temp);
    }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  power[0] = 1;
  for (int i = 1; i < N; ++i)
    power[i] = power[i - 1] * p % m;
  while (t--) {
    int n, cnt = 0;
    cin>>A>>B>>n;
    mp.clear();
    for (int i = 0; i < A.length(); ++i)
      amap[i].clear();
    vmap.clear();
    for (int i = 0; i < n; ++i) {
      cin>>S[i]>>bi[i];
      mp.insert({S[i], bi[i]});
      ll s1, s2;
      s1 = 0;
      for (int j = 0; j < S[i].length() - 1; ++j) {
	s1 = (s1 + (S[i][j] - 'a' + 1) * power[j]) % m;
	s2 = 0;
	for (int k = j + 1; k < S[i].length(); ++k)
	  s2 = (s2 + (S[i][k] - 'a' + 1) * power[k - j - 1]) % m;
	if (vmap.find(s1) == vmap.end()) {
	  vmap.insert({s1, cnt++});
	  vec[cnt - 1].push_back({s2, bi[i]});
	}
	else {
	  int id = vmap.at(s1);
	  vec[id].push_back({s2, bi[i]});
	}
      }
    }
    precomp(n);
    ll ans = solve();
    cout<<ans<<endl;
    for (int i = 0; i < cnt; ++i)
      vec[i].clear();
  }
  return 0;
}
