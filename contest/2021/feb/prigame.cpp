#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6;
vector <int> primes;

void find_primes(int n) {

  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {

    bool factor = false;
    for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        factor = true;
        break;
      }
    }

    if (factor == false) { primes.push_back(i); }
  }

  return;
}

int main() {

  find_primes(N);

  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    auto it = upper_bound(primes.begin(), primes.end(), x);
    int prime_cnt = it - primes.begin();

    // cout << prime_cnt << endl;
    if (prime_cnt <= y)
      puts("Chef");
    else
      puts("Divyam");
  }
  return 0;
}
