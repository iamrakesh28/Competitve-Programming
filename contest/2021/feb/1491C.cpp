#include <iostream>

using namespace std;

const int N = 5e3 + 5;
int S[N], path[N];

bool correct(int n) {

  for (int i = 0; i < n; ++i)
    if (S[i] > 1) {
      return false;
    }

  return true;
}

bool possible(int n) {

  bool poss = true;
  path[n - 1] = 1;
  int cnt = 0;

  int max_p = 1, ind = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (S[i] + i < n) {
      path[i] = path[S[i] + i] + 1;
    }
    else {
      path[i] = 1;
    }
    if (path[i] > max_p) {
      max_p = path[i];
      ind = i;
    }
  }

  int i = ind;
  while (i < n) {
    if (S[i] > 1)
      cnt++;
    i = S[i] + i;
  }

  if (cnt <= 1)
    return false;

  i = ind;
  while (i < n) {
    int temp = S[i];
    S[i] = max(S[i] - 1, 1);
    i = temp + i;
  }
  
  return poss;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      scanf("%d", S + i);
    }

    long long ans = 0;
    while (true) {
      if (correct(n))
        break;
      if (possible(n)) {
        ans++;
      }
      else {
        for (int i = 0; i < n; ++i) {
          if (S[i] > n - i - 1) {
            ans += (S[i] - (n - i - 1));
            S[i] = n - 1 - i;
          }
        }
      }
    }

    printf("%lld\n", ans);
  }
  
  return 0;
}
