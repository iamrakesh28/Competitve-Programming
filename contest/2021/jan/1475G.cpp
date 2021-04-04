#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
vector <int> fact[N];
int a[N], lis[N];

void preprocess() {

  for (int i = 1; i < N; ++i) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        fact[i - 1].push_back(j);
        if (j * j != i)
          fact[i - 1].push_back(i / j);
      }
    }
  }

  return;
}

int find_lis(int n) {

  fill(lis, lis + N, 0);
  for (int i = 0; i < n; ++i) {
    lis[a[i] - 1] = max(lis[a[i] - 1], lis[a[i] - 1] + 1);
    if (a[i] != 1)
      lis[a[i] - 1] = max(lis[a[i] - 1], lis[0] + 1);
    
    for (int j : fact[a[i] - 1])
      lis[a[i] - 1] = max(lis[a[i] - 1], lis[j - 1] + 1);
  }

  int len = 1;
  for (int i = 0; i < n; ++i)
    len = max(len, lis[a[i] - 1]);

  return len;
}

int main() {

  int t;
  scanf("%d", &t);

  preprocess();
  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    sort(a, a + n);
    int len = find_lis(n);
    // cout << lis[0] << " " << lis[1] << " " << lis[2] << endl;
    printf("%d\n", n - len);
  }
  
  return 0;
}
