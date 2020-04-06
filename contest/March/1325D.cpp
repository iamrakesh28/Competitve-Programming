#include <iostream>

using namespace std;

/*
  3 => [u, x, x]
  x = (v - u) / 2

  a + b = a ^ b + 2 * (a & b)
  a + b = v
  a ^ b = u
  a & b = x
*/

bool solve(long long u, long long x, long long &a, long long &b) {
  bool ans = true;
  for (int j = 0; j < 63; ++j) {
    if ((1LL << j) & x) {
      a = a | (1LL << j);
      b = b | (1LL << j);
      if ((1LL << j) & u) {
	ans = false;
	break;
      }
    }
    else {
      if ((1LL << j) & u)
	a = a | (1LL << j);
    }
  }
  return ans;
}
int main() {
  long long u, v;
  scanf("%lld%lld", &u, &v);
  if (v < u) {
    puts("-1");
    return 0;
  }
  long long a, b, x;
  x = v ^ u;
  if (x & 1) {
    puts("-1");
    return 0;
  }
  if (u == v && u == 0) {
    puts("0");
    return 0;
  }
  if (u == v) {
    printf("1\n%lld\n", u);
    return 0;
  }
  a = b = 0;
  x = (v - u) / 2;
  bool poss = solve(u, x, a, b);
  if (poss)
    printf("2\n%lld %lld\n", a, b);
  else
    printf("3\n%lld %lld %lld\n", u, x, x);
  return 0; 
}
