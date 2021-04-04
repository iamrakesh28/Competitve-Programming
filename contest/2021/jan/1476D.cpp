#include <iostream>

using namespace std;

const int N = 3e5 + 5;
char s[N];
int left_[N][2], right_[N][2];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d%s", &n, s);

    for (int i = 0; i < 2; ++i)
      left_[0][i] = right_[n][i] = 1;
    
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == 'L') {
        left_[i][0] = left_[i - 1][1] + 1;
        left_[i][1] = 1;
      }
      else {
        left_[i][1] = left_[i - 1][0] + 1;
        left_[i][0] = 1;
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'R') {
        right_[i][0] = right_[i + 1][1] + 1;
        right_[i][1] = 1;
      }
      else {
        right_[i][1] = right_[i + 1][0] + 1;
        right_[i][0] = 1;
      }
    }
    
    for (int i = 0; i <= n; ++i) {
      int ans = left_[i][0] + right_[i][0] - 1;
      printf("%d ", ans);
    }

    puts("");
  }
  
  return 0;
}
