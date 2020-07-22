#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
ll a[505];
vector <int> vec[62];

int belong(set <int> &s, int j) {
  int cnt = 0;
  for (int i = 0; i < vec[j].size(); ++i) {
    if (s.find(vec[j][i]) != s.end())
      cnt++;
  }
  return cnt;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a + i);
  for (int i = 62; i >= 0; i--) {
    for (int j = 0; j < n; ++j)
      if ((1LL << i) & a[j])
	vec[i].push_back(j);
  }
  set <int> cand;
  ll ans = 0;
  int ind = -1;
  for (int i = 62; i >= 0; i--) {
    if (vec[i].size()) {
      for (int v : vec[i])
	cand.insert(v);
      ind = i;
      break;
    }
  }
  ans = 1LL << ind;
  for (int i = ind - 1; i >= 0; i--) {
    int bel = belong(cand, i);
    if (bel && bel >= cand.size() - 2)
      ans = ans + (1LL << i);
    if (bel && bel < cand.size() - 5)
      continue;
    
  }
  return 0;
}
