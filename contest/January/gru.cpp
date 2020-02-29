#include <iostream>

using namespace std;

long long bin(long long n, long long k) {
  long long ans = -1;
  long long sum, diff;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sum = 2 * i + (k - 1) * i;
      sum = sum / 2;
      if (sum <= n) {
	sum = k * sum;
	diff = n - sum;
	if (diff >= 0)
	  ans = max(ans, i);
      }
      //if (diff % i == 0)
      //ans = max(ans, i);

      long long j = n / i;
      sum = 2 * j + (k - 1) * j;
      sum = sum / 2;
      if (sum <= n) {
	sum = k * sum;
	diff = n - sum;
	if (diff >= 0)
	  ans = max(ans, j);
      }
      //if (diff % j == 0)
      //ans = max(ans, j);
    }
  }
  return ans;
}

int main() {

  int q;
  scanf("%d", &q);
  while (q--) {
    long long  n, k;
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", bin(n, k));
  }
  return 0;
}
