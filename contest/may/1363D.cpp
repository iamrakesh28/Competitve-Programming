#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e3 + 5;
vector <int> an;
set <int> c[N];

bool find(int maxm, int beg, int end) {
  int val, size = end - beg + 1;
  printf("? %d", size);
  for (int i = beg; i <= end; ++i)
    printf(" %d", i + 1);
  puts("");
  fflush(stdout);
  scanf("%d", &val);
  if (val == maxm)
    return true;
  return false;
}

void solve(int n, int k, int maxm) {
  int beg = 0, end = n - 1, mid, ans;
  while (beg <= end) {
    mid = beg + end >> 1;
    // cout<<beg<<" "<<mid<<" "<<end<<endl;
    if (find(maxm, beg, mid)) {
      end = mid;
      if (beg == mid) {
	ans = beg;
	break;
      }
    }
    else {
      beg = mid + 1;
      if (beg == end) {
	ans = beg;
	//cout<<ans<<endl;
	break;
      }
    }
  }
  int ind = -1;
  for (int i = 0; i < k; ++i) {
    if (c[i].find(ans) != c[i].end()) {
      ind = i;
      continue;
    }
    an[i] = maxm;
  }
  //cout<<ind+1<<endl;
  if (ind == -1)
    return;
  printf("? %d", n - c[ind].size());
  for (int i = 0; i < n; ++i) {
    if (c[ind].find(i) != c[ind].end())
      continue;
    printf(" %d", i + 1);
  }
  puts("");
  fflush(stdout);
  scanf("%d", &maxm);
  an[ind] = maxm;
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i)
      c[i].clear();
    an.clear();
    an.resize(k);
    for (int i = 0; i < k; ++i) {
      int s;
      scanf("%d", &s);
      for (int j = 0; j < s; ++j) {
	int val;
	scanf("%d", &val);
	c[i].insert(val - 1);
      }
    }
    printf("? %d", n);
    for (int i = 0; i < n; ++i)
      printf(" %d", i + 1);
    puts("");
    fflush(stdout);
    int maxm;
    scanf("%d", &maxm);
    solve(n, k, maxm);
    printf("!");
    for (int i = 0; i < k; ++i)
      printf(" %d", an[i]);
    puts("");
    fflush(stdout);
    char S[10];
    scanf("%s", S);
  }
  return 0;
}
