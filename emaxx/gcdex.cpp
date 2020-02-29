#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
bool primes[N];
int phi[N];
long long ans[N];
vector <int> prime, factors[N];
vector <pair <int, int>> fact[N];

int Phi(int n) {
  int num = n, result = n;
  for (int it : prime) {
    if ((long long)it * it > n)
      break;
    if (n % it == 0) {
      int size = fact[num].size() + 1;
      fact[num].push_back({it, 1});
      n = n / it;
      while (n % it == 0) {
	int temp = fact[num][size - 1].second;
	fact[num][size - 1].second++;
	n = n / it;
      }
      result = result - result / it;
    }
  }
  if (n > 1) {
    result -= result / n;
    fact[num].push_back({n, 1});
  }
  return result;
}

void factCal(int num, int i, int val) {
  if (i == 0) {
    factors[num].push_back(val);
    return;
  }
  int times = 1;
  for (int j = 0; j <= fact[num][i - 1].second; ++j) {
    factCal(num, i - 1, times * val);
    times = times * fact[num][i - 1].first;
  }
  return;
}

int main() {
  
  memset(primes, true, sizeof primes);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= N - 1; ++i) {
    if (primes[i] == false)
      continue;
    prime.push_back(i);
    for (int j = i * i; j <= N - 1; j += i)
      primes[j] = false;
  }
  phi[1] = 1;
  for (int i = 2; i <= N - 1; ++i) {
    if (primes[i]) {
      phi[i] = i - 1;
      fact[i].push_back({i, 1});
      factCal(i, 1, 1);
      continue;
    }
    phi[i] = Phi(i);
    factCal(i, fact[i].size(), 1);
    /*
    if (i < 20) {
      printf("%d : ", i);
      for (int it : factors[i])
	cout<<it<<" ";
      puts("");
    }
    */
  }
  factCal(1, 0, 1);
  for (int i = 2; i < N; ++i) {
    long long temp = 0;
    for (int it : factors[i])
      if (it != i)
	temp = temp + (long long)it * phi[i / it];
    ans[i] = temp;
    if (i > 2)
      ans[i] += ans[i - 1];
  }
  int n;
  while (scanf("%d", &n) != EOF && n)
    printf("%lld\n", ans[n]);
  return 0;
}
  
