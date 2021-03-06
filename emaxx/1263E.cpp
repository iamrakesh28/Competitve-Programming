#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
int prefixMax[N], suffixMax[N], prefixMin[N], suffixMin[N];
char s[N];


int main() {
  int n, i = 0, cnt = 0, ans, temp;
  scanf("%d", &n);
  // memset(prefixMin, N, sizeof prefixMin);
  // memset(suffixMin, N, sizeof suffixMin);
  char ch = getchar();
  while ((ch = getchar()) != '\n') {
    if (ch != 'L' && ch != 'R') {
      s[i] = ch;
      int val = 0;
      if (s[i] == '(')
	val = 1;
      else if (s[i] == ')')
	val = -1;
      prefixMax[i + 1] = max(prefixMax[i], prefixMax[i] + val);
      suffixMax[i + 1] = max(suffixMax[i + 2], suffixMax[i + 2] + val);
      prefixMin[i + 1] = min(prefixMin[i], prefixMin[i] + val);
      suffixMin[i + 1] = min(suffixMin[i + 2], suffixMin[i + 2] + val);
    }
    else if (ch == 'L'){
      i--;
      int val = 0;
      if (s[i] == ')')
	val = -1, cnt++;
      else if (s[i] == '(')
	val = 1, cnt--;
      suffixMax[i + 1] = max(suffixMax[i + 2], suffixMax[i + 2] + val);
      suffixMin[i + 1] = min(suffixMin[i + 2], suffixMin[i + 2] + val);
    }
    else {
      if (s[i] == ')')
	cnt--;
      else if (s[i] == '(')
	cnt++;
      i++;
      int val = 0;
      if (s[i] == ')')
	val = -1;
      else if (s[i] == '(')
	val = 1;
      prefixMax[i + 1] = max(prefixMax[i], prefixMax[i] + val);
      prefixMin[i + 1] = max(prefixMin[i], prefixMin[i] + val);
    }
    temp = min(prefixMin[i], cnt + suffixMin[i + 1]);
    ans = max(prefixMax[i], cnt + suffixMax[i + 1]);
    cout<<cnt<<" "<<temp<<" ";
    printf("%d\n", ans);
  }
  return 0;
}
