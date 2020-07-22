#include <iostream>
#include <set>

using namespace std;

int arr[505];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    set <int> s1, s2;
    scanf("%d", &n);
    s1.clear();
    s2.clear();
    for (int i = 0; i < n; ++i)
      scanf("%d", arr + i);
    for (int i = 0; i < n; ++i) {
      int b;
      scanf("%d", &b);
      if (b)
	s1.insert(b);
      else
	s2.insert(b);
    }
    int pos = 1;
    for (int i = 1; i < n; ++i)
      if (arr[i - 1] > arr[i])
	pos = -1;
    if (pos == 1) {
      puts("Yes");
      continue;
    }
    if (s1.size() == 0 || s2.size() == 0) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}
