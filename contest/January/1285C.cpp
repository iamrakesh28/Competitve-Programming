#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long x, ans, a, b;
  cin>>x;
  ans = x;
  a = 1, b = x;
  for (long long i = 1; i * i <= x; ++i) {
    if (x % i == 0 && __gcd(i, x / i) == 1) {
      long long j = x / i, mn;
      mn = max(i, j);
      //cout<<mn<<endl;
      if (ans > mn) {
	a = i, b = j;
	ans = mn;
      }
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}
