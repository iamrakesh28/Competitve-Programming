#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

const int N = 1e5 + 5, alphabet = 256;
char s[N], t[2005];
int p[N], c[N], cnt[N], pn[N], cn[N], inv[N];

void sort_cyclic(int n) {
  for (int i = 0; i < alphabet; ++i)
    cnt[i] = 0;

  for (int i = 0; i < n; ++i)
    cnt[s[i]]++;
  for (int i = 1; i < alphabet; ++i)
    cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; ++i)
    p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]])
      classes++;
    c[p[i]] = classes - 1;
  }

  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; ++i) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0)
	pn[i] += n;
    }

    for (int i = 0; i < classes; ++i)
      cnt[i] = 0;

    for (int i = 0; i < n; ++i)
      cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; ++i)
      cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
      p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; ++i) {
      pair <int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair <int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
      if (cur != prev)
	++classes;
      cn[p[i]] = classes - 1;
    }
    for (int i = 0; i < n; ++i)
      c[i] = cn[i];
  }
  for (int i = 0; i < n; ++i)
    inv[p[i]] = i;
  /*for (int i = 0; i < n; ++i) {
    for (int j = p[i]; j < n; ++j)
      cout<<s[j];
    cout<<endl;
    }*/
}

int compare(int l, int mid, int n) {
  if (l + mid - 1 >= n)
    return -1;
  for (int i = 0; i < l; ++i) {
    if (t[i] < s[i + mid])
      return -1;
    else if (t[i] > s[i + mid])
      return 1;
  }
  return 0;
}
bool found(int l, int n) {
  int beg = 0, end = n - 1, mid;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    int val = compare(l, inv[mid], n);
    if (val == 0)
      return true;
    else if (val < 0)
      end = mid - 1;
    else
      beg = mid + 1;
  }
  return false;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  assert(n < N);
  sort_cyclic(n);
  int m;
  scanf("%d", &m);
  //char ch = getchar();
  while (m--) {
    scanf("%s", t);
    //ch = getchar();
    int l = strlen(t);
    assert(l < 2005);
    if (found(l, n))
      puts("Y");
    else
      puts("N");
  }
  return 0;
}
