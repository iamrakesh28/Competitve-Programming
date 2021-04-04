#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char x[N], y[N];

void fill_str(int k, int a, int b) {

  int n = a + b;
  int diff = n - k - 2;
  diff++;

  for (int i = 0; i < n; ++i) {
    x[i] = y[i] = '0';
  }
  
  for (int i = 0; i < diff; ++i) {
    x[i] = y[i] = '1';
    b--;
  }

  for (int i = 0; i < b; ++i) {
    x[diff + i] = '1';
  }

  for (int i = 0; i < b - 1; ++i) {
    y[diff + i + 1] = '1';
  }
  y[n - 1] = '1';
  
  x[n] = y[n] = '\0';
  
  return;
}

int main() {

  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  
  if (b == 1 || a == 0) {
    if (k > 0)
      puts("NO");
    else {
      puts("YES");
      if (a == 0) {
        memset(x, '1', sizeof(char) * (a + b));
        memset(y, '1', sizeof(char) * (a + b));
        x[a + b] = y[a + b] = '\0';
      }
      else
        fill_str(k, a, b);
      printf("%s%s\n", x, y);
    }

    return 0;
  }

  int max_k = a + b - 2;
  if (k > max_k) {
    puts("NO");
  }
  else {
    puts("YES");
    fill_str(k, a, b);
    printf("%s%s\n", x, y);
  }
  return 0;
}
