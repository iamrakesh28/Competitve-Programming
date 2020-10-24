#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int li[N];
vector <int> len;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", li + i);
  sort(li, li + n);
  len.clear();
  ll ans = 0;
  int i = n - 2;
  while (i >= 0) {
    if (li[i] == li[i + 1] || li[i] == li[i + 1] - 1) {
      len.push_back(li[i]);
      i -= 2;
    }
    else
      i--;
  }
  if (len.size() == 0) {
    puts("0");
    return 0;
  }
  for (int v = 0; v < len.size() - 1; v += 2) {
    ans = ans + (ll)len[v] * len[v + 1];
    //cout << len[v] << " " << len[v + 1] << endl;
  }
  cout << ans << endl;
  //printf("%lld\n", ans);
  return 0;
}
