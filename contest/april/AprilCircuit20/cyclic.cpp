#include <iostream>

using namespace std;

const int N = 16;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m, ans = 0;
    char c;
    scanf("%d%d %c", &n, &m, &c);
    for (int i = N - 1; i >= 0; i--) {
      int pos;
      if (c == 'L')
	pos = (i + m) % N;
      else
	pos = (i - m + N) % N;
      //cout<<i<<" "<<pos<<endl;
      if (n & (1 << i))
	ans = ans | (1 << pos);
    }
    printf("%d\n", ans);
  }
  return 0;
}
