#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int A[N], par[N];
bool mark[N], visit[N];

int main() {
  int n, root, poss = 1;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", A + i);
    mark[i] = visit[i] = false;
  }
  mark[n - 1] = visit[n - 1] = false;
  root = A[0];
  visit[root - 1] = true;
  int j = n;
  for (int i = 0; i < n - 2; ++i) {
    mark[A[i] - 1] = true;
    while (j > 0 && visit[j - 1])
      j--;
    //cout<<i<<" "<<j<<endl;
    if (mark[A[i + 1] - 1] == false && visit[A[i + 1] - 1] == false)
	par[A[i + 1]] = A[i], visit[A[i + 1] - 1] = true;
    else
      par[j--] = A[i], visit[j] = true;
  }
  while (j > 0 && visit[j - 1])
    j--;
  par[j--] = A[n - 2];
  /*
  if (poss == 0) {
    puts("-1");
    return 0;
  }
  */
  printf("%d\n", root);
  for (int i = 1; i <= n; ++i)
    if (par[i])
      printf("%d %d\n", par[i], i);
  return 0;
}
