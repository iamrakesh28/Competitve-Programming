#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e7 + 5, mod = 1e9 + 7;
bool primes[N];
int phi[N], primen[N];
long long factor[N];
vector <int> prime;

int Phi(int n) {
  int num = n, result = n, flag = 0, val = 1;
  for (int it : prime) {
    if ((long long)it * it > n)
      break;
    if (n % it == 0) {
      n = n / it;
      val = val * it;
      while (n % it == 0) {
	n = n / it;
	val = val * it;
      }
      if (n != 1)
	result = phi[val] * phi[n];
      else
	result = result - result / it;
      flag = 1;
      break;
    }
  }
  if (n > 1 && flag == 0)
    result -= result / n;
  return result;
}

long long power(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1)
      r = r * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return r;
}

int main() {
  int cnt = 0;
  memset(primes, true, sizeof primes);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= N - 1; ++i) {
    primen[i] = cnt;
    if (primes[i] == false)
      continue;
    prime.push_back(i);
    cnt++;
    for (int j = i * i; j <= N - 1; j += i)
      primes[j] = false;
  }
  phi[1] = 1;
  for (int i = 2; i <= N - 1; ++i) {
    if (primes[i]) {
      phi[i] = i - 1;
      continue;
    }
    phi[i] = Phi(i);
  }
  factor[0] = 1;
  for (int i = 1; i < N; ++i)
    factor[i] = factor[i - 1] * i % mod;
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    int fn = max(primen[n] - phi[n], 0);
    long long ans = factor[fn];
    ans = power(phi[n], factor[ans]);
    printf("%lld\n", ans);
  }
  return 0;
}
  
