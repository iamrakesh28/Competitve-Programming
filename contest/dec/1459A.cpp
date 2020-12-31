#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  vector <char> rd;
  while (t--) {
    int n;
    scanf("%d", &n);
    rd.resize(n);

    int red = 0, blue = 0;
    for (int i = 0; i < n; ++i) {
      char dig;
      scanf(" %c", &dig);
      rd[i] = dig;
    }

    for (int i = 0; i < n; ++i) {
      char dig;
      scanf(" %c", &dig);
      if (dig > rd[i])
        blue++;
      else if (dig < rd[i])
        red++;
    }

    if (red == blue)
      puts("EQUAL");
    else if (red > blue)
      puts("RED");
    else
      puts("BLUE");
  }
  
  return 0;
}
