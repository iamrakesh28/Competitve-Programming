#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

const int N = 105;
char B[N], pre[N];

/*
  0 -> comp
  1 -> reverse
  2 -> comp + rev
  3 -> same
*/

void update(int b, int move) {
  for (int i = 0; i < b; ++i) {
    if (pre[i] == '-') {
      B[i] = '-';
      continue;
    }
    int rev = b - i - 1;
    switch (move) {
    case 0: B[i] = '1' - pre[i] + '0';
      break;
    case 1: B[i] = pre[rev];
      break;
    case 2: B[i] = '1' - pre[rev] + '0';
      break;
    default: B[i] = pre[i];
    }
  }
  for (int i = 0; i < b; ++i)
    pre[i] = B[i];
  return;
}

int chal(int same, int opp) {
  int move;
  char p, pr;
  if (same != -1 && opp != -1) {
    printf("%d\n%d\n", same + 1, opp + 1);
    fflush(stdout);
    scanf(" %c %c", &p, &pr);
    if (pre[same] == p) {
      if (pre[opp] == pr)
	move = 3;
      else
	move = 1;
    }
    else {
      //cout<<"a\n"<<opp+1<<" "<<pr<<endl;;
      if (pre[opp] == pr)
	move = 2;
      else {
	move = 0;
	//cout<<"b\n";
      }
    }
  }
  else {
    int ind = opp;
    if (same != -1)
      ind = same;
    printf("%d\n%d\n", ind + 1, ind + 1);
    fflush(stdout);
    scanf(" %c %c", &p, &p);
    if (pre[ind] == p)
      move = 3;
    else
      move = 0;
  }
  return move;
}

int main() {
  int t, b;
  scanf("%d%d", &t, &b);
  while (t--) {
    int same = -1, opp = -1, half = b / 2, move, rev;
    char p, pr;
    memset(B, '-', sizeof(char) * b);
    memset(pre, '-', sizeof(char) * b);
    for (int i = 0; i < 5; i++) {
      rev = b - i - 1;
      printf("%d\n%d\n", i + 1, rev + 1);
      fflush(stdout);
      scanf(" %c %c", &p, &pr);
      if (p == pr) {
	same = i;
	pre[i] = pre[rev] = p;
      }
      else {
	opp = i;
	pre[i] = p;
	pre[rev] = pr;
      }
    }
    if (b == 10) {
      move = chal(same, opp);
      //cout<<same+1<<" "<<opp+1<<endl;
      update(b, move);
    }
    int cur = 5;
    while (cur < half) {
      move = chal(same, opp);
      update(b, move);
      for (int i = 0; i < 4 && cur + i < half; ++i) {
	rev = b - cur - i - 1;
	printf("%d\n%d\n", cur + i + 1, rev + 1);
	fflush(stdout);
	scanf(" %c %c", &p, &pr);
	if (p == pr) {
	  same = cur + i;
	  pre[cur + i] = pre[rev] = p;
	}
	else {
	  opp = cur + i;
	  pre[cur + i] = p;
	  pre[rev] = pr;
	}
      }
      cur += 4;
    }
    pre[b] = '\0';
    puts(pre);
    fflush(stdout);
    char y;
    scanf(" %c", &y);
    if (y != 'Y')
      break;
  }
  return 0;
}
