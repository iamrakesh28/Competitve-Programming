#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

LL city[N];
int start[N];
vector <vector <int>> _end;

void solve(int q, int n) {

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    start[l - 1]++;

    int len = r - l + 1;
    if (r < n)
      _end[r].push_back(len);
  }

  LL cursum = 0;
  int cnt = 0;
  
  for (int i = 0; i < n; ++i) {

    for (int num : _end[i]) {
      cnt--;
      cursum -= num;
    }

    cursum = cursum + cnt;
    
    if (start[i]) {
      cnt += start[i];
      cursum += start[i];
    }

    city[i] = cursum;
  }

  return;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);

    memset(city, 0, sizeof(LL) * n);
    memset(start, 0, sizeof(int) * n);

    _end.resize(n);
    
    for (int i = 0; i < n; ++i)
      _end[i].clear();

    solve(q, n);

    for (int i = 0; i < n; ++i)
      printf("%lld ", city[i]);

    puts("");
  }
  
  return 0;
}
