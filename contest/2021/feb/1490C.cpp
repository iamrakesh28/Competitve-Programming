#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

const LL N = 1e12 + 5;
vector <LL> cubes;

int main() {

  int t;
  scanf("%d", &t);

  LL cube = 1;
  while (cube * cube * cube <= N) {
    cubes.push_back(cube * cube * cube);
    cube++;
  }
  
  while (t--) {
    LL x;
    scanf("%lld", &x);

    cube = 1;
    int a = 1;
    bool found = false;
    while (cube <= x) {
      LL a3 = cube;
      LL b3 = x - a3;

      auto it = lower_bound(cubes.begin(), cubes.end(), b3);
      if (it != cubes.end()) {
        if ((*it) == b3) {
          found = true;
          break;
        }
      }
      a++;
      cube = (LL)a * (LL)a * (LL)a;
    }

    if (found)
      puts("YES");
    else
      puts("NO");
  }
  
  return 0;
}
