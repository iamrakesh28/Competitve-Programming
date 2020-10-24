#include <iostream>

using namespace std;
int keys[26];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    char a, A;
    scanf(" %c %c", &a, &A);
    keys[a - 'a']++;
    if (keys[A - 'A'])
      keys[A - 'A']--;
    else
      ans++;
  }
  printf("%d\n", ans);
  return 0;
} 
