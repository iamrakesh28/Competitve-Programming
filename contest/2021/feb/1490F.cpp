#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 2e5 + 5;
int a[N], freq[N];
LL sum[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    sort(a, a + n);
    int id = 0, cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
        freq[id++] = cnt;
        cnt = 1;
      }
      else
        cnt++;
    }
    freq[id++] = cnt;
    sort(freq, freq + id);

    sum[0] = 0;
    for (int i = 0; i < id; ++i) {
      sum[i + 1] = sum[i] + freq[i];
    }

    int C = 1, idx = 0;
    LL ans = 1e9;
    while (C <= n && idx < id) {

      while (idx < id && freq[idx] < C) {
        idx++;
      }

      if (idx >= id)
        break;
      
      LL temp;
      LL del = sum[idx], rem;
      rem = n - del;
      temp = del;

      LL bar = (LL)(id - idx) * C;
      rem = rem - bar;
      temp += rem;

      ans = min(ans, temp);

      // cout << C << " " << temp << " " << bar << endl;
      C++;
    }

    printf("%d\n", ans);
  }
  
  return 0;
}
