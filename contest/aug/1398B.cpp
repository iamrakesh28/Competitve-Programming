#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 105;
char s[N];
vector <int> seq;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    seq.clear();
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
	if (cnt)
	  seq.push_back(cnt);
	cnt = 0;
      }
      else {
	  cnt++;
      }
    }
    if (cnt)
      seq.push_back(cnt);
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());
    int sum = 0;
    for (int i = 0; i < seq.size(); i += 2)
      sum += seq[i];
    printf("%d\n", sum);
  }
  return 0;
}
