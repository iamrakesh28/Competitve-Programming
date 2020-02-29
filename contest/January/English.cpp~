#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;

const int N = 2e5 + 5, alphabet = 256;
char s[N];
int cnt[N], p[N], c[N], cn[N], pn[N], lcp[N], ran[N], new_lcp[N], entry[N], st[N][20], logn[N + 1];
pair <int, int> v[N];

void suffix(int n) {
  for (int i = 0; i < alphabet; ++i)
    cnt[i] = 0;
  for (int i = 0; i < n; ++i)
    cnt[s[i]]++;
  for (int i = 1; i < alphabet; ++i)
    cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; ++i)
    p[--cnt[s[i]]] = i;
  int classes = 1;
  c[p[0]] = 0;
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]])
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

  /*
  for (int i = 0; i < n; ++i) {
    for (int j = p[i]; j < n; ++j)
      cout<<s[j];
    cout<<endl;
  }
  */
  
  return;
}

void lcp_cons(int n) {
  for (int i = 0; i < n; ++i)
    ran[p[i]] = i;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (ran[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = p[ran[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k])
      ++k;
    lcp[ran[i]] = k;
    if (k)
      k--;
  }
  return;
}

void sparse(int n) {
  
    logn[1] = 0;
    for (int i = 2; i <= 1e5 + 5; i++)
      logn[i] = logn[i / 2] + 1;
    for (int i = 0; i < n; ++i)
      st[i][0] = new_lcp[i];

    for (int j = 1; j <= 19; ++j)
      for (int i = 0; i + (1 << j) <= n; i++)
	st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, len = 0;
    long long ans = 0;
    char ch;
    scanf("%d", &n);
    ch = getchar_unlocked();
    for (int i = 0; i < n; ++i) {
      v[i].first = len;
      while ((ch = getchar_unlocked()) != '\n')
	s[len++] = ch;
      s[len++] = '$';
      v[i].second = len - v[i].first - 1;
    }
    if (n == 1) {
      puts("0");
      continue;
    }
    suffix(len);
    lcp_cons(len);
    for (int i = 0; i < n; ++i)
      v[i].first = ran[v[i].first];
    sort(v, v + n);

    for (int i = v[0].first, j = -1; i < v[n - 1].first; ++i) {
      if (v[j + 1].first == i) {
	if (j != -1) {
	  new_lcp[j] = min(min(v[j].second, v[j + 1].second), new_lcp[j]);
	  //cout<<new_lcp[j]<<" "<<i<<" "<<j<<endl;
	}
	new_lcp[++j] = lcp[i];
	//cout<<lcp[i]<<endl;
      }
      new_lcp[j] = min(new_lcp[j], lcp[i]);
    }
    new_lcp[n - 2] = min(min(v[n - 2].second, v[n - 1].second), new_lcp[n - 2]);
    // for (int i = 0; i < n; ++i)
    //  cout<<v[i].first<<" "<<v[i].second<<endl;

    sparse(n - 1);
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
	vi = min(st[a][j], st[b - (1 << j) + 1][j]);
	//cout<<vi<<" "<<a<<" "<<b<<endl;
	interval.insert({vi, {a, b + 1}});
      }
    }
    //ans = max(ans, temp);
    printf("%lld\n", ans);
  }
  return 0;
}
