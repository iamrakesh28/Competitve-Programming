#include <iostream>

using namespace std;

char s[105];
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int cnt = 0, n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
	int sum = 0;
	for (int k = i; k <= j; ++k) {
	  if (s[k] == '(')
	    sum++;
	  else if (s[k] == ')')
	  sum--;
	  if (sum < 0) {
	    sum += 2;
	    cnt++;
	  }
	}
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
