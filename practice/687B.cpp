#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
bool isPrime[N];
vector <int> primes;
int C[N];

void findPrimes(int n) {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (isPrime[i])
      primes.push_back(i);
    if (isPrime[i] && (long long)i * i <= n)
      for (int j = i * i; j <= n; j += i)
	isPrime[j] = false;
  }
  return;
}

void primeFactors(int n) {
  int cnt = 0;
  for (int v : primes) {
    if ((long long)v * v > n)
      break;
    while (n % v == 0) {
      n = n / v;
      cnt++;
    }
    C[v] = max(C[v], cnt);
    cnt = 0;
  }

  if (n > 1)
    C[n] = max(C[n], 1);
  return;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  findPrimes(N - 2);
  for (int i = 0; i < n; ++i) {
    int ci;
    scanf("%d", &ci);
    primeFactors(ci);
  }
  bool ok = true;
  int cnt = 0;
  for (int v : primes) {
    if ((long long)v * v > k)
      break;
    while (k % v == 0) {
      k = k / v;
      cnt++;
    }
    if (cnt > C[v]) {
      ok = false;
      break;
    } 
    cnt = 0;
  }
  if (k > 1) {
    if (1 > C[k])
      ok = false;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
