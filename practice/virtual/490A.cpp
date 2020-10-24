#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector <int> t1, t2, t3;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int ai;
    scanf("%d", &ai);
    switch (ai) {
    case 1 : t1.push_back(i + 1); break;
    case 2 : t2.push_back(i + 1); break;
    default : t3.push_back(i + 1);
    }
  }
  int ans = min(t1.size(), min(t2.size(), t3.size()));
  printf("%d\n", ans);
  int i = 0;
  while (ans--) {
    printf("%d %d %d\n", t1[i], t2[i], t3[i]);
    i++;
  }
  return 0;
}
