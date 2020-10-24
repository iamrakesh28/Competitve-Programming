#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;
char s[N];
int mod[N];

int main() {
  int m;
  scanf("%s%d", s, &m);
  int n = strlen(s);
  while (m--) {
    int ai;
    scanf("%d", &ai);
    ai--;
    mod[ai]++;
    mod[n - ai]--;
  }
  for (int i = 0; i < n / 2; ++i) {
    if (i)
      mod[i] += mod[i - 1];
    mod[i] = mod[i] % 2;
    if (mod[i] & 1) {
      char c = s[n - i - 1];
      s[n - i - 1] = s[i];
      s[i] = c;
    }
  }
  puts(s);
  return 0;
}
