#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 105, P = 200;

int row[N], col[N];
bool prime[P];
vector <int> num;

int main() {
  int t;
  scanf("%d", &t);
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;

  for (int i = 2; i < P; ++i) {
    if (prime[i])
      for (int j = i * i; j < P; j += i)
	prime[j] = false;
  }

  while (t--) {
    int n;
    num.clear();
    scanf("%d", &n);
    int prim = -1, sum;
    for (int i = n; i < P; ++i)
      if (prime[i] && (i - (n - 1)) >= 6) {
	sum = i;
	int diff = i - n + 1;
	prim = diff;
	if (prime[diff])
	  prim -= 3;
	break;
      }

    num.push_back(prim);
    sum -= prim;
    for (int i = 1; i < n; ++i) {
      if (i == n - 1)
	num.push_back(sum);
      else
	num.push_back(1);
      sum--;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
	printf("%d ", num[(j + i) % n]);
      puts("");
    }
  }
  return 0;
}
