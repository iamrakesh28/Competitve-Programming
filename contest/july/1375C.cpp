#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 5;
int a[N];
vector <int> vec;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    vec.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    int hill = 0;
    if (a[0] < a[1]) {
      hill++;
      vec.push_back(a[0]);
    }
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
	vec.push_back(a[i]);
	hill++;
      }
    }
    if (hill == 0) {
      puts("YES");
      continue;
    }
    if (a[n - 1] < a[n - 2]) {
      hill++;
      vec.push_back(a[n - 1]);
    }
    int last = vec[vec.size() - 1];
    if (vec.size() == 1) {
      puts("NO");
      continue;
    }
    int f = -1;
    for (int i = 0; i < vec.size() - 1; ++i)
      f = max(f, vec[i]);
    if (last > f)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
