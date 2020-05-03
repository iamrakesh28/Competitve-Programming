#include <iostream>
#include <cstring>

using namespace std;

pair <int, int> time(char s[]) {
  int h = 0, m = 0, i, n = strlen(s);
  for (i = 0; i < n; ++i) {
    if (s[i] == ':')
      break;
    int x = s[i] - '0';
    h = 10 * h + x;
  }
  i++;
  for (; i < n; ++i) {
    if (s[i] == ':')
      break;
    int x = s[i] - '0';
    m = 10 * m + x;
  }
  return {h, m};
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, sleep = 0, awake = 0, ph = -1, pm;
    char s1[10], s2[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int h1, m1, h2, m2;
      scanf("%s%s", s1, s2);
      auto it = time(s1);
      h1 = it.first;
      m1 = it.second;
      it = time(s2);
      h2 = it.first;
      m2 = it.second;
      //cout<<h1<<" "<<m1<<" "<<h2<<" "<<m2<<endl;
      if (h2 < h1) {
	sleep = sleep + (24 - h1 - 1) * 60;
	sleep = sleep + 60 - m1;
	sleep += h2 * 60 + m2;
      }
      else {
	sleep = sleep + (h2 - h1 - 1) * 60;
	sleep += m2;
	sleep += 60 - m1;
      }
      if (ph != -1) {
	if (ph > h1) {
	  awake = awake + (24 - ph - 1) * 60;
	  awake = awake + 60 - pm;
	  awake += h1 * 60 + m1;
	}
	else {
	  awake = awake + (h1 - ph - 1) * 60;
	  awake += m1;
	  awake += 60 - pm;
	}
      }
      //cout<<awake<<" "<<sleep<<endl;
      ph = h2;
      pm = m2;
    }
    printf("Case #%d: %d %d\n", q + 1, awake, sleep);
  }
  return 0;
}
