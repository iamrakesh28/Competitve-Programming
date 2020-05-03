#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3 + 5;

int a[N], freq[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    memset(freq, 0, sizeof freq);
    cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
	if (cnt > 1) {
	  if (cnt & 1)
	    freq[a[i - 1] - 1] += (cnt / 2 + 1);
	  else
	    freq[a[i - 1] - 1] += (cnt / 2);
	}
	else
	  freq[a[i - 1] - 1]++;
	cnt = 1;
      }
      else
	cnt++;
    }
    int i = n;
    if (cnt > 1) {
      if (cnt & 1)
	freq[a[i - 1] - 1] += (cnt / 2 + 1);
      else
	freq[a[i - 1] - 1] += (cnt / 2);
    }
    else
      freq[a[i - 1] - 1]++;
    int ans = 0, id = 0;
    for (int i = 0; i < N; ++i) {
      if (freq[i] > ans) {
	ans = freq[i];
	id = i;
      }
    }
    printf("%d\n", id + 1);
  }
  return 0;
}
