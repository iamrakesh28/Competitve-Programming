#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
char a[N], b[N];
vector <int> vec;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, l, r, cnt = 0, ans = 0;
    vec.clear();
    scanf("%d%s%s", &n, a, b);
    l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (cnt & 1) {
	char val = a[r];
	if (val == '1')
	  val = '0';
	else
	  val = '1';
	cnt++;
	r--;
	if (val != b[i]) {
	  ans++;
	  vec.push_back(i + 1);
	}
	else {
	  ans += 2;
	  vec.push_back(1);
	  vec.push_back(i + 1);
	}
      }
      else  {
	char val = a[l];
	cnt++;
	l++;
	if (val != b[i]) {
	  ans++;
	  vec.push_back(i + 1);
	}
	else {
	  ans += 2;
	  vec.push_back(1);
	  vec.push_back(i + 1);
	}
      }
    }
    printf("%d", ans);
    for (int v : vec)
      printf(" %d", v);
    puts("");
  }
  return 0;
}
