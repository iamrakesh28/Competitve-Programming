#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
char s[N];
int d1[N], d2[N];

long long D1(int n) {
  memset(d1, 0, sizeof(int) * n);
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
      k++;
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    sum += d1[i];
  return sum;
}

long long D2(int n) {
  memset(d2, 0, sizeof(int) * n);
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
      k++;
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i)
    sum += d2[i];
  return sum;
}

int main() {

  int q;
  scanf("%d", &q);
  while (q--) {
    long long d;
    scanf("%s%lld", s, &d);
    int len = strlen(s), und = 0;
    for (int i = 0; i < len; ++i)
      if (s[i] == '_') {
	und = i;
	break;
      }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      s[und] = 'a' + i;
      //puts(s);
      long long sum = D1(len);
      //cout<<sum<<" ";
      sum = abs(sum - D2(len));
      //cout<<sum<<endl;
      if (sum == d) {
	ans = i;
	break;
      }
    }
    printf("%c\n", 'a' + ans);
  }
  return 0;
}
