#include <iostream>
#include <set>

using namespace std;

const int N = 2e5 + 5, K = 1e7 + 1;
int a[N];
bool calc[K];
int power[K];

int factorize(int num) {

  int cnt = 0;
  int prod = 1;
  if (num % 2 == 0) {
    while (num % 2 == 0) {
      num = num >> 1;
      cnt = (cnt + 1) % 2;
    }
    if (cnt > 0)
      prod *= 2;
  }
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      cnt = 0;
      while (num % i == 0) {
        num = num / i;
        cnt = (cnt + 1) % 2;
      }
      if (cnt > 0)
        prod *= i;
    }
  }

  if (num > 1) {
    prod *= num;
  }
  
  return prod;
}

int main() {

  int t;
  scanf("%d", &t);

  power[1] = 1;
  calc[1] = true;
  for (int i = 2; i <= K; ++i)
    calc[i] = false;

  /*
  power[1] = 1;
  for (int i = 2; i <= K; ++i) {
    power[i] = factorize(i);
  }
  */

  set <int> cur;
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    cur.clear();
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    int ans = 1;
    if (calc[a[0]])
      cur.insert(power[a[0]]);
    else {
      power[a[0]] = factorize(a[0]);
      cur.insert(power[a[0]]);
      calc[a[0]] = true;
    }

    for (int i = 1; i < n; ++i) {

      if (calc[a[i]] == false) {
        power[a[i]] = factorize(a[i]);
        calc[a[i]] = true;
      }
      
      int val = power[a[i]];
      if (cur.find(val) == cur.end()) {
        cur.insert(val);
      }
      else {
        cur.clear();
        
        cur.insert(val);
        ans++;
      }
    }
    
    printf("%d\n", ans);
  }
  
  return 0;
}
