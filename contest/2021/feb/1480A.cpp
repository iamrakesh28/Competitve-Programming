#include <iostream>
#include <cstring>

using namespace std;

const int N = 55;
char s[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        if (s[i] == 'z')
          s[i] = 'y';
        else
          s[i] = 'z';
      }
      else {
        if (s[i] == 'a')
          s[i] = 'b';
        else
          s[i] = 'a';
      }
    }
    
    puts(s);
  }
  
  return 0;
}
