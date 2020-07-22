#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5, inf = 1e9 + 5;
pair <int, int> a[N];
int size[N], pres[N], par[N];

int find(int u) {
  if (u == par[u])
    return u;
  int v = find(par[u]);
  par[u] = v;
  return v;
}

void join(int u, int v) {
  u = find(u);
  v = find(v);
  if (size[u] >= size[v]) {
    size[u] += size[v];
    par[v] = u;
  }
  else {
    size[v] += size[u];
    par[u] = v;
  }
}

int half(int v) {
  if (v & 1)
    v = v / 2 + 1;
  else
    v = v / 2;
  return v;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int ai;
    scanf("%d", &ai);
    a[i] = {ai, i};
    par[i] = i;
    size[i] = 1;
  }
  sort(a, a + n);
  memset(pres, -1, sizeof pres);
  int num = k / 2, odd = 0, one = -1;
  if (k & 1)
    odd = 1;
  int ans = inf, prev = 0;
  for (int i = 0; i < n; ++i) {
    int ind = a[i].second, s1 = 0, s2 = 0;
    if (ind == 0)
      one = 1;
    if (ind) {
      if (pres[ind - 1] == 1) {
	s1 = size[ind - 1];
	join(ind, ind - 1);
      }
      if (pres[ind + 1] == 1) {
	s2 = size[ind + 1];
	join(ind, ind - 1);
      }
      pres[ind] = 1;
    }
    else {
      if (pres[ind + 1] == 1) {
	s2 = size[ind + 1];
	join(ind, ind - 1);
      }
      pres[ind] = 1;
    }
    if (s1 && s2)
      prev = prev + half(s1 + s2 + 1) - half(s1) - half(s2);
    else if (s1)
      prev = prev + half(s1 + 1) - half(s1);
    else if (s2)
      prev = prev + half(s2 + 1) - half(s2);
    else
      prev++;
    if (odd && one == 1) {
      if (size[find(0)] & 1) {
	if (prev >= num + 1) {
	  ans = a[i].first;
	  break;
	}
      }
      else {
	if (prev >= num) {
	  ans = a[i].first;
	  break;
	}
      }
    }
    else {
      if (prev >= num) {
	ans = a[i].first;
	break;
      }
    }
    //cout<<num<<endl;
  }
  printf("%d\n", ans);
  return 0;
}
