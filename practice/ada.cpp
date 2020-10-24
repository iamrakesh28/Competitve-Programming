#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 3e5 + 5, alphabet = 256;
char s[N];
int p[N], c[N], pn[N], cn[N], cnt[N], inv[N], lcp[N];
ll ans[26];

void suffix(int n) {
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
    fill(cnt, cnt + classes, 0);
    for (int i = 0; i < n; ++i)
      cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; i++)
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
  //for (int i = 0; i < n; ++i)
  //  cout<<s + p[i]<<endl;
}

void lcp_cons(int n) {
  for (int i = 0; i < n; ++i)
    inv[p[i]] = i;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (inv[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = p[inv[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k])
      k++;
    lcp[inv[i]] = k;
    if (k)
      k--;
  }
  //  for (int i = 0; i < n - 1; ++i)
  //  cout<<lcp[i]<<" ";
  //  puts("");
}

int main() {
  int n;
  scanf("%s", s);
  n = strlen(s);
  s[n] = '#', s[n + 1] = '\0';
  n++;
  //cout<<s<<endl;
  suffix(n); 
  lcp_cons(n);
  n--;
  ans[s[p[1]] - 'a'] = n - p[1];
  for (int i = 1; i < n; ++i) {
    //cout<<lcp[i]<<" ";
    ans[s[p[i + 1]] - 'a'] += n - (p[i + 1] + lcp[i]);
    //cout<<ans[s[p[i + 1]] - 'a']<<endl;
  }
  for (int i = 0; i < 26; ++i)
    printf("%lld ", ans[i]);
  puts("");
  return 0;
}
