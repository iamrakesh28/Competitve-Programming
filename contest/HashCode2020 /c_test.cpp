#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int si[N];
struct Lib {
  int nj, tj, mj, ind;
} LIB[N];

vector <int> lib[N];

bool compare(struct Lib &a, struct Lib &b) {
  return a.tj < b.tj;
}

int main() {
  int b, l, d, nnj = -1, ttj = 0, mmj = 1e9;
  scanf("%d%d%d", &b, &l, &d);
  for (int i = 0; i < b; ++i)
    scanf("%d", si + i);
  for (int i = 0; i < l; ++i) {
    int nj, tj, mj;
    scanf("%d%d%d", &nj, &tj, &mj);
    nnj = max(nj, nnj);
    ttj += tj;
    mmj = min(mmj, mj);
    for (int j = 0; j < nj; ++j) {
      int id;
      scanf("%d", &id);
      //lib[i].push_back(id);
    }
  }
  cout<<nnj<<" "<<ttj<<" "<<mmj<<endl;
  /*
  sort(LIB, LIB + l, compare);
  printf("%d\n", l);
  for (int i = 0; i < l; ++i) {
    int ind = LIB[i].ind;
    printf("%d %d\n", ind, lib[ind].size());
    for (int v : lib[ind])
      printf("%d ", v);
    puts("");
    }*/
  return 0;
}
