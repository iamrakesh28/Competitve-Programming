#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
LL d[N << 1], sorted[N], a[N];

bool solve(int n) {

  bool poss = true;
  int cnt = n;
  LL sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    LL ai = sorted[i] - sum;
    if (ai < 0 || (ai & 1)) {
      poss = false;
      break;
    }
    ai = ai >> 1;
    if (ai % cnt) {
      poss = false;
      break;
    }

    ai = ai / cnt;
    a[i] = ai;
    sum = sum + (ai << 1);
    cnt--;
  }

  sort(a, a + n);
  if (a[0] == 0)
    poss = false;
  
  //cout << a[0] << " ";
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      poss = false;
      break;
    }
    //cout << a[i] << " ";
  }
  //cout << endl;
  
  
  return poss;
}

int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    bool poss = true;
    int sz = n << 1;
    for (int i = 0; i < sz; ++i) {
      scanf("%lld", d + i);
      if (d[i] & 1)
        poss = false;
    }

    if (poss == false) {
      puts("NO");
      continue;
    }
    sort(d, d + sz);
    int ind = 0;
    for (int i = 0; i < sz; i += 2) {
      if (d[i] != d[i + 1]) {
        poss = false;
        break;
      }
      sorted[ind++] = d[i];
    }
    if (poss == false) {
      puts("NO");
      continue;
    }

    poss = solve(n);
    if (poss) {
      puts("YES");
    }
    else {
      puts("NO");
    }
  }
  return 0;
}
