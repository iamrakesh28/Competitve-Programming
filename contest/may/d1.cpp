#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
bool satan[N];
bool dp[N];

int main() {
  int t;
  scanf("%d", &t);
  memset(satan, false, sizeof satan);
  for (int i = 1; i <= N; ++i) {
    int prod = 1;
    for (int j = 1; j <= i; ++j)
      prod *= i;
    if (prod > N)
      break;
    satan[prod] = true;
  }

  for (int i = 1; i <= N; ++i) {
    if (satan[i] == true) {
      dp[i] = true;
      continue;
    }
    dp[i] = false;
    int num = i, q, r;
    while (num) {
      r = num % 10;
      if (i > r * r)
	dp[i] = dp[i] || dp[i - r * r];
      num /= 10;
    }
  }
  while (t--) {
    int n;
    scanf("%d", &n);
    if (dp[n])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
