#include <iostream>
#include <stack>

using namespace std;

const int prime = 1e9 + 7, N = 1e7 + 5;
char s[N];
stack <long long> sq;

long long power(long long a) {
  long long r = 1;
  int n = prime - 2;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n = n >> 1;
  }
  return r;
}

void swap(long long *x, long long *y) {
  long long temp = *x;
  *x = *y;
  *y = temp;
  return;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long ans = 0;
    scanf("%d%s", &n, s);
    while (sq.size())
      sq.pop();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
	long long top = 1;
	if (sq.size()) {
	  top = top + sq.top();
	  sq.pop();
	}
	sq.push(top);
	sq.push(0);
      }
      else if (s[i] == ')'){
	long long zero = 0, one = 0, two = 0, temp;
	if (sq.size()) {
	  zero = sq.top();
	  sq.pop();
	}
	if (sq.size()) {
	  one = sq.top();
	  sq.pop();
	}
	temp = zero + 1;
	swap(&zero, &one);
	one++;
	if (sq.size()) {
	  two = sq.top();
	  sq.pop();
	}
	one += two;
	sq.push(one);
	sq.push(zero);
	ans = ans + ((long long)temp * (n - i)) % prime;
	ans = ans % prime;
      }
      else {
	long long top = 1;
	if (sq.size()) {
	  top = top + sq.top();
	  sq.pop();
	}
	sq.push(top);
      }
    }
    //cout<<ans<<endl;
    long long inv = (long long)n * (n + 1);
    inv = inv >> 1;
    inv = inv % prime;
    ans = ans * power(inv) % prime;
    printf("%lld\n", ans);
  }
  return 0;
}
