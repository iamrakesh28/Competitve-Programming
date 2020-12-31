#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;

char x[N];
int cnt[32];

int getcount(int k) {
  int cnt = 0;
  while (k) {
    k = k & (k - 1);
    cnt++;
  }
  return cnt;
}

bool solve(int k, int n) {

  memset(cnt, 0, sizeof cnt);

  int diff = n - getcount(k);

  if (diff < 0)
    return false;
  
  for (int i = 30; i >= 0; i--) {
 
    if ((1 << i) & k)
      cnt[i] += 1;

    if (cnt[i] && diff) {
      int move = min(diff, cnt[i]);

      if (i) {
        diff -= move;
        cnt[i - 1] += (move << 1);
        cnt[i] -= move;
      }
    }
  }

  if (diff)
    return false;

  int index = 0;
  for (int i = 0; i < 31; ++i) {
    while (cnt[i]) {
      x[index++] = i + 'a';
      cnt[i]--;
    }
  }

  x[index] = '\0';
  
  return true;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    if (solve(k, n) == false) {
      puts("-1");
      continue;
    }

    puts(x);
  }
  
  return 0;
}
