#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;
const int N = 5e3 + 5, p = 31, prime = 1e9 + 9;
char s[N];
ll power[N], hs[N];
int kpal[N];
map <ll, int> pal; 

void precomp() {
  power[0] = 1;
  for (int i = 1; i < N; ++i)
    power[i] = (power[i - 1] * p) % prime;
}

int main() {
  precomp();
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      hs[j - i + 1] = (h[j - i] + (s[j] - 'a' + 1)) % prime;
    }
  }
  return 0;
}
