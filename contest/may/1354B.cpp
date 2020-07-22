#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1e9;
char S[200005];
vector <int> vec[3];

int solve(int i, int j, int k) {
  int ans = inf;
  for (int it : vec[i]) {
    auto it2 = lower_bound(vec[j].begin(), vec[j].end(), it);
    if (it2 == vec[j].end())
      break;
    int val = *it2;
    it2 = lower_bound(vec[k].begin(), vec[k].end(), val);
    if (it2 == vec[k].end())
      break;
    val = *it2;
    ans = min(ans, val - it + 1);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%s", S);
    n = strlen(S);
    for (int i = 0; i < 3; ++i)
      vec[i].clear();
    for (int i = 0; i < n; ++i) {
      if (S[i] == '1')
	vec[0].push_back(i);
      else if (S[i] == '2')	
	vec[1].push_back(i);
      else
	vec[2].push_back(i);
    }
    bool f = true;
    for (int i = 0; i < 3; ++i)
      if (vec[i].size() == 0) {
	f = false;
	break;
      }
    if (f == false) {
      puts("0");
      continue;
    }
    int ans = solve(0, 1, 2);
    ans = min(ans, solve(0, 2, 1));
    ans = min(ans, solve(1, 0, 2));
    ans = min(ans, solve(1, 2, 0));
    ans = min(ans, solve(2, 1, 0));
    ans = min(ans, solve(2, 0, 1));
    printf("%d\n", ans);
  }
  return 0;
}
