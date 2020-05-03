#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5, inf = 1e9, size = 700;
int a[N], freq[N], ans[N];

struct Query {
  int l, r, id, k, block;
} query[N];

bool compare(Query &a, Query &b) {
  if (a.block != b.block)
    return a.block < b.block;
  return (a.block & 1) ? (a.r < b.r) : (a.r > b.r);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--, r--;
    query[i] = {l, r, i, k, l / size};
  }
  sort(query, query + q, compare);
  int curl = 0, curr = -1;
  set <int> mn[4];
  for (int i = 0; i < q; ++i) {
    int l, r, id, val, temp;
    l = query[i].l;
    r = query[i].r;
    id = query[i].id;
    val = query[i].k;
    for (int k = 2; k <= 5; ++k) {
      temp = (r - l + 1) / k;
      temp++;
      while (curl > l) {
	curl--;
	int v = freq[a[curl]]++;
	if (v == temp - 1)
	  mn[k - 2].insert(a[curl]);
	else if (v == temp)
	  mn[k - 2].erase(mn[k - 2].find(a[curl]));
      }

      while (curr < r) {
	curr++;
	int v = freq[a[curr]]++;
	if (v == temp - 1)
	  mn[k - 2].insert(a[curr]);
	else if (v == temp)
	  mn[k - 2].erase(mn[k - 2].find(a[curr]));
      }
      if (k == 2)
	cout<<mn[0].size()<<" "<<temp<<endl;
      while (curl < l) {
	int v = freq[a[curl]]--;
	if (v == temp + 1)
	  mn[k - 2].insert(a[curl]);
	else if (v == temp)
	  mn[k - 2].erase(mn[k - 2].find(a[curl]));
	curl++;
      }
      while (curr > r) {
	int v = freq[a[curr]]--;
	//cout<<v<<" "<<temp<<endl;
	if (v == temp + 1)
	  mn[k - 2].insert(a[curr]);
	else if (v == temp)
	  mn[k - 2].erase(mn[k - 2].find(a[curr]));
	curr--;
      }
    }
    
    ans[id] = -1;
    if (mn[val - 2].size())
      ans[id] = *mn[val - 2].begin();
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
