#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 5;

map <pair<int, int>, int> mp;

int getmax() {
}

void update(int r, int g, int b) {
  for (int i = r; i < N; i = i | (i + 1))
    for (int j = y; j < N; j = j | (j + 1)) {
      if (mp.find({i, j}) == mp.end())
	mp[{i, j}] = b;
      else
	mp[{i, j}] = max(mp[{i, j}], b)
    }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  
  return 0;
}
