#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 25;
const ll inf = 1e16;

vector <int> ai;
vector <ll> fact;

ll solve(int n, ll sum) {
  if (n == 0) {
    if (sum == 0)
      return 1;
    return 0;
  }
  ll ans = 0;
  if (sum >= ai[n - 1])
    ans = ans + solve(n - 1, sum - ai[n - 1]);
  if (sum >= fact[ai[n - 1]]) {
    //cout << ai[n - 1] << " " << fact[ai[n - 1]] << endl;
    ans = ans + solve(n - 1, sum - fact[ai[n - 1]]);
  }
  return ans;
}

int main() {

  fact.push_back(1);
  ll f = 1;
  int num = 1;
  while (f <= inf) {
    f = num * f;
    fact.push_back(f);
    num++;
  }
  int n, k;
  ll s;
  scanf("%d%d%lld", &n, &k, &s);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a >= fact.size())
      continue;
    ai.push_back(a);
  }
  n = ai.size();
  ll ans = solve(n, s);
  printf("%lld\n", ans);
  return 0;
}
