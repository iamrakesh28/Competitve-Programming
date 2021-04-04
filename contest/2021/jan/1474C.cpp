#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);
  vector <int> a;

  while (t--) {
    int n;
    scanf("%d", &n);

    a.resize(n << 1);
    for (int i = 0; i < (n << 1); ++i)
      scanf("%d", &a[i]);

    sort(a.begin(), a.end());
  }
  
  return 0;
}
