#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

void solve() {
  int temp[5];
  puts(
       "XOR 1 2\n"
       "XOR 2 3\n"
       "AND 1 2\n"
       "AND 2 3\n"
       "AND 1 3"
       );
  fflush(stdout);
  for (int i = 0; i < 5; ++i)
    scanf("%d", temp + i);
  
  a[0] = a[1] = a[2] = 0;
  for (int i = 15; i >= 0; i--) {
    if ((temp[0] & (1 << i)) == 0) {
      int bit1 = temp[2] & (1 << i);
      a[0] = a[0] | bit1;
      a[1] = a[1] | bit1;
      int bit2 = temp[1] & (1 << i);
      a[2] = a[2] | (bit1 ^ bit2);
      continue;
    }
    if ((temp[1] & (1 << i)) == 0) {
      int bit1 = temp[3] & (1 << i);
      a[1] = a[1] | bit1;
      a[2] = a[2] | bit1;
      int bit2 = temp[0] & (1 << i);
      a[0] = a[0] | (bit1 ^ bit2);
      continue;
    }
    int bit1 = temp[4] & (1 << i);
    a[0] = a[0] | bit1;
    a[2] = a[2] | bit1;
    int bit2 = temp[0] & (1 << i);
    a[1] = a[1] | (bit1 ^ bit2);
  }
  
  return;
  
}

int main() {

  int n;
  scanf("%d", &n);
  a.resize(n);
  solve();
  for (int i = 3; i < n; ++i) {
    printf("XOR 1 %d\n", i + 1);
    fflush(stdout);
    int ai;
    scanf("%d", &ai);
    a[i] = ai ^ a[0];
  }
  printf("! ");
  for (int ai : a)
    printf("%d ", ai);
  puts("");
  return 0;
}
