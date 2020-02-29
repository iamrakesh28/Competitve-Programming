#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;

const int N = 2e5 + 5, alphabet = 256;
char s[N], rev[N];
int cnt[N], p[N], c[N], cn[N], pn[N], lcp[N], ran[N], new_lcp[N], rev_lcp[N], st_lcp[N], entry[N], st1[N][20], st2[N][20], logn[N + 1];
int vstr[N / 2], A[N / 2], B[N / 2];
pair <int, int> v[N];

struct info {
  int len, start, pref, suff;
} str[N];

bool compare(int a, int b) {
  int i, j, ls, lp, lg, sa, sb;
  sa = str[a].pref, sb = str[b].pref;
  if (sa < sb)
    i = sa, j = sb - 1;
  else
    i = sb, j = sa - 1;
  lg = logn[j - i + 1];
  lp = min(st1[i][lg], st1[j - (1 << lg) + 1][lg]);

  sa = str[a].suff, sb = str[b].suff;
  if (sa < sb)
    i = sa, j = sb - 1;
  else
    i = sb, j = sa - 1;
  lg = logn[j - i + 1];
  ls = min(st2[i][lg], st2[j - (1 << lg) + 1][lg]);

  ls = min(ls, lp);
  if (str[a].len == ls)
    return true;
  else if (str[b].len == ls)
    return false;
  else {
    char s1 = s[str[a].start + ls], s2 = s[str[b].start + ls];
    //cout<<s1<<" "<<s2<<endl;
    if (s1 < s2)
      return true;
    else if (s1 > s2)
      return false;
    else {
      s1 = rev[str[a].start + ls], s2 = rev[str[b].start + ls];
      return s1 < s2;
    }
  }
}

void merge(int abc[], int l, int mid, int r) {

  int i, j, k, l1, l2;
  for (i = l; i <= r; ++i)
    A[i - l] = abc[i];
  i = 0, j = mid - l + 1, k = l;
  l1 = mid - l + 1;
  l2 = r - l + 1;

  while (i < l1 && j < l2) {
    if (compare(A[i], A[j]))
      abc[k++] = A[i++];
    else
      abc[k++] = A[j++];
  }
  while (i < l1)
    abc[k++] = A[i++];
  while (j < l2)
    abc[k++] = A[j++];
  return;
}

void mergeSort(int abc[], int l, int r) {
  if (r > l) {
    int mid = (l + r) >> 1;
    mergeSort(abc, l, mid);
    mergeSort(abc, mid + 1, r);
    merge(abc, l, mid, r);
  }
  return;
}

void suffix(int n, char *sf) {
  for (int i = 0; i < alphabet; ++i)
    cnt[i] = 0;
  for (int i = 0; i < n; ++i)
    cnt[sf[i]]++;
  for (int i = 1; i < alphabet; ++i)
    cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; ++i)
    p[--cnt[sf[i]]] = i;
  int classes = 1;
  c[p[0]] = 0;
  for (int i = 1; i < n; ++i) {
    if (sf[p[i]] != sf[p[i - 1]])
      ++classes;
    c[p[i]] = classes - 1;
  }
  
  for (int h = 0; (1 << h) <  n; ++h) {
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
    classes = 1;
    cn[p[0]] = 0;
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

  //sf[n] = '\0';
  //cout<<sf<<endl;
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = p[i]; j < n; ++j)
      cout<<sf[j];
    cout<<endl;
  }
  */
  
  return;
}

void lcp_cons(int n, char *sf) {
  for (int i = 0; i < n; ++i)
    ran[p[i]] = i;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (ran[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = p[ran[i] + 1];
    while (i + k < n && j + k < n && sf[i + k] == sf[j + k])
      ++k;
    lcp[ran[i]] = k;
    if (k)
      k--;
  }
  return;
}

void sparse(int n, int *new_lcp, int st[][20]) {
  
    for (int i = 0; i < n; ++i)
      st[i][0] = new_lcp[i];

    for (int j = 1; j <= 19; ++j)
      for (int i = 0; i + (1 << j) <= n; i++)
	st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    return;
}

void solve(int n, int len) {
  suffix(len, s);
  lcp_cons(len, s);

  for (int i = 0; i < n; ++i)
    v[i].first = ran[str[i].start];
  sort(v, v + n);

  for (int i = 0; i < n; ++i)
    str[v[i].second].pref = i;

  int cur, nxt;
  for (int i = v[0].first, j = -1; i < v[n - 1].first; ++i) {
    if (v[j + 1].first == i) {
      if (j != -1) {
	cur = v[j].second, nxt = v[j + 1].second;
	st_lcp[j] = min(min(str[cur].len, str[nxt].len), st_lcp[j]);
      }
      st_lcp[++j] = lcp[i];
      //cout<<lcp[i]<<endl;
    }
    st_lcp[j] = min(st_lcp[j], lcp[i]);
  }
  cur = v[n - 2].second, nxt = v[n - 1].second;
  st_lcp[n - 2] = min(min(str[cur].len, str[nxt].len), st_lcp[n - 2]);

  suffix(len, rev);
  lcp_cons(len, rev);

  for (int i = 0; i < n; ++i)
    v[i].first = ran[str[i].start], v[i].second = i;
  sort(v, v + n);

  for (int i = 0; i < n; ++i)
    str[v[i].second].suff = i;

  for (int i = v[0].first, j = -1; i < v[n - 1].first; ++i) {
    if (v[j + 1].first == i) {
      if (j != -1) {
	cur = v[j].second, nxt = v[j + 1].second;
	rev_lcp[j] = min(min(str[cur].len, str[nxt].len), rev_lcp[j]);
      }
      rev_lcp[++j] = lcp[i];
      //cout<<lcp[i]<<endl;
    }
    rev_lcp[j] = min(rev_lcp[j], lcp[i]);
  }
  cur = v[n - 2].second, nxt = v[n - 1].second;
  rev_lcp[n - 2] = min(min(str[cur].len, str[nxt].len), rev_lcp[n - 2]);

  sparse(n - 1, st_lcp, st1);
  sparse(n - 1, rev_lcp, st2);

  //for (int i = 0; i < n - 1; ++i) {
  //cout<<st_lcp[i]<<" "<<rev_lcp[i]<<endl;
  //}

  return;
}

int main() {
  int q;
  scanf("%d", &q);
  logn[1] = 0;
  for (int i = 2; i <= 1e5 + 5; i++)
    logn[i] = logn[i / 2] + 1;

  while (q--) {
    int n, len = 0;
    long long ans = 0;
    char ch;
    scanf("%d", &n);
    ch = getchar_unlocked();
    for (int i = 0; i < n; ++i) {
      str[i].start = len;
      while ((ch = getchar_unlocked()) != '\n')
	s[len++] = ch, rev[len - 1] = ch;
      reverse(rev + str[i].start, rev + len);
      s[len++] = '$';
      rev[len - 1] = '$';
      //str[i].i = i;
      str[i].len = len - str[i].start - 1;
      v[i].second = i;
      vstr[i] = i;
    }
    if (n == 1) {
      puts("0");
      continue;
    }

    solve(n, len);
    //sort(vstr, vstr + n, compare);
    mergeSort(vstr, 0, n - 1);
    for (int i = 0; i < n - 1; ++i) {
      int a, b, ls, lp, lg, sa, sb;
      sa = str[vstr[i]].pref, sb = str[vstr[i + 1]].pref;
      if (sa < sb)
	a = sa, b = sb - 1;
      else
	a = sb, b = sa - 1;
      lg = logn[b - a + 1];
      lp = min(st1[a][lg], st1[b - (1 << lg) + 1][lg]);

      sa = str[vstr[i]].suff, sb = str[vstr[i + 1]].suff;
	if (sa < sb)
	  a = sa, b = sb - 1;
	else
	  a = sb, b = sa - 1;
	lg = logn[b - a + 1];
	ls = min(st2[a][lg], st2[b - (1 << lg) + 1][lg]);
	
	ls = min(ls, lp);
	new_lcp[i] = ls;
	//cout<<ls<<" ";
    }
    
    sparse(n - 1, new_lcp, st1);
    set <int> ind;
    ind.insert(0);
    set <pair<int, pair <int, int>>> interval;
    for (int i = 0; i < n - 1; ++i) {
      interval.insert({new_lcp[i], {i, i + 1}});
      ind.insert(i + 1);
      entry[i] = 1;
    }
    entry[n - 1] = 1;

    while (interval.size() && ind.size()) {
      auto it = interval.end();
      it--;
      interval.erase(it);
      int a, b, vi;
      a = (*it).second.first, b = (*it).second.second;
      vi = (*it).first;
      //cout<<vi<<" "<<a<<" "<<b<<endl;
      if (entry[a] != -1 && entry[b] != -1) {
	ans = ans + (long long)vi * vi;
	ind.erase(a);
	ind.erase(b);
	entry[a] = entry[b] = -1;
	auto it1 = ind.upper_bound(b);
	if (it1 == ind.end())
	  continue;
	b = *it1 - 1;
	it1 = ind.lower_bound(a);
	if (it1 == ind.begin())
	  continue;
	it1--;
	a = *it1;
	int j = logn[b - a + 1];
	vi = min(st1[a][j], st1[b - (1 << j) + 1][j]);
	//cout<<vi<<" "<<a<<" "<<b<<endl;
	interval.insert({vi, {a, b + 1}});
      }
    }
    //ans = max(ans, temp);
    
    printf("%lld\n", ans);
  }
  return 0;
}
