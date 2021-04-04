#include <iostream>

using namespace std;

int cntBit(int num) {
  if (num == 0)
    return 0;

  int cnt = 0;
  while (num) {
    num = num & (num - 1);
    cnt++;
  }

  return cnt;
}

bool solve(int u, int v) {
  
  bool poss = true;
  int cnt1 = 0, cnt2 = 0;

  for (int i = 0; i < 30; ++i) {
    if (u & (1 << i))
      cnt1++;
    if (v & (1 << i))
      cnt2++;

    if (cnt2 > cnt1) {
      poss = false;
      break;
    }
  }

  if (poss == false)
    return false;

  int l = -1;
  for (int i = 29; i >= 0; i--) {
    if (v & (1 << i)) {
      if ((u & (1 << i)) == 0) {
        l = i;
        break;
      }
    }
  }

  cnt1 = cnt2 = 0;
  for (int i = l + 1; i < 30; ++i) {
    if (u & (1 << i))
      cnt1++;
    if (v & (1 << i))
      cnt2++;
    
    if (cnt1 > cnt2) {
      poss = false;
      break;
    }
  }
    
  return poss;
}

int main() {

  int q;
  scanf("%d", &q);

  while (q--) {
    
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) {
      puts("NO");
      continue;
    }

    int c1 = cntBit(u), c2 = cntBit(v);
    if (c1 < c2) {
      puts("NO");
      continue;
    }

    bool poss = solve(u, v);
    if (poss)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
