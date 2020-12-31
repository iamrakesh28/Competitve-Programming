#include <iostream>

using namespace std;

const int N = 1e3 + 5;
int b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", b + i);
    bool poss = false;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
	if (b[i] == b[j]) {
	  poss = true;
	  break;
	}
	if (poss)
	  break;
      }
  
    if (poss)
      puts("YES");
    else
      puts("NO");

  }
  return 0;
}
