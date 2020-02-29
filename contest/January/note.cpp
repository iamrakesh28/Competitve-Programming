#include <iostream>
#include <cassert>

using namespace std;

int main() {

  int n;
  long long one = 0, two = 0, three = 0, four = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int ai;
    scanf("%d", &ai);
    if (ai == 1)
      one++;
    else if (ai == 2)
      two++;
    else if (ai == 3)
      three++;
    else
      four++;
  }
  if (one == n) {
    puts("2");
  }
  else if (one == n - 1) {
    puts("1");
  }
  else {
    int win = 0;
    while (three + four) {
      if (two & 1)
	four--, two++;
      else {
	if (four)
	  four--, two += 2;
	else
	  win = 1 - win;
      }
    }
    cout<<win+1<<endl;
  }
  return 0;
}
