#include <iostream>
#include <time.h>

using namespace std;

const long int N = 1e18;

int main() {
  int t = 15;
  printf("%d\n", t);
  srand(time(NULL));
  while (t--) {
    long long n = rand( )% N + N - 100;
    printf("%lld\n", n);
  }
  return 0;
}
