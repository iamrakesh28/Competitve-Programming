#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

int p[N], L[N], R[N], maxm = -1, c = 0;
vector <int> pos;

bool solve(int i) {

  int l = i - L[i], r = R[i] - i;
  int mx = max(l, r), mn = min(l, r);
  mx = max(mx, maxm);
  if (mx > mn)
    return false;

  
  if (mx & 1)
    return false;

  if (c > 1)
    return false;
  
  return true;
}

void compute(int posi, int n) {

  int i;
  for (i = posi; i < n - 1; ++i) {
    if (p[i + 1] > p[i])
      break;
  }
  R[posi] = i;

  for (i = posi; i > 0; --i) {
    if (p[i - 1] > p[i])
      break;
  }
  L[posi] = i;

  int temp = max(posi - L[posi], R[posi] - posi);
  if (temp == maxm)
    c++;
  else if (maxm < temp){
    maxm = temp;
    c = 1;
  }
  return;
}

int main() {

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
  }

  for (int i = 1; i < n - 1; ++i) {
    if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
      pos.push_back(i);
    }
  }

  for (int posi : pos) {
    compute(posi, n);
    // cout << posi + 1 << " " << L[posi] + 1 << " " << R[posi] + 1 << endl;
  }
  
  int cnt = 0;
  for (int posi : pos) {
    if (solve(posi))
      cnt++;
  }

  printf("%d\n", cnt);
  return 0;
}
