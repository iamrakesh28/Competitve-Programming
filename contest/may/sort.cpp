#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5 + 5;

int p[N], inv[N];

vector <int> ans[3];

int solve(int n, int k) {
  set <pair <int, int>> cycle;
  for (int i = 0; i < n; ++i) {
    if (p[i] == i)
      continue;
    int a = p[i], b, c;
    b = p[p[i]];
    if (i == b) {
      cycle.insert({min(i, p[i]), max(i, p[i])});
      continue;
    }
    k--;
    b = inv[i];
    //cout<<i+1<<" "<<a+1<<" "<<b+1<<endl;
    ans[0].push_back(i);
    ans[1].push_back(a);
    ans[2].push_back(b);
    c = p[a];
    p[a] = p[i];
    p[b] = c;
    p[i] = i;
    inv[c] = b;
  }
  if (cycle.size() & 1)
    return -1;
  auto it1 = cycle.begin();
  while (it1 != cycle.end()) {
    auto it2 = it1;
    it2++;
    int a, b, c, d;
    k -= 2;
    a = (*it1).first, b = (*it1).second;
    c = (*it2).first, d = (*it2).second;
    ans[0].push_back(b);
    ans[1].push_back(a);
    ans[2].push_back(c);

    ans[0].push_back(b);
    ans[1].push_back(d);
    ans[2].push_back(c);
    it1++;
    it1++;
  }
  return k;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    for (int i = 0; i < 3; ++i)
      ans[i].clear();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", p + i);
      p[i]--;
      inv[p[i]] = i;
    }
    k = solve(n, k);
    if (k < 0) {
      puts("-1");
      continue;
    }
    printf("%d\n", ans[0].size());
    for (int i = 0; i < ans[0].size(); ++i)
      printf("%d %d %d\n", ans[0][i] + 1, ans[1][i] + 1, ans[2][i] + 1);
  }
  return 0;
}
