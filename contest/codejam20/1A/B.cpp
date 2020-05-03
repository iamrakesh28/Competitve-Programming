#include <iostream>
#include <list>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 50;
ll pascal[N][N];
list <pair <int, int> > ans;

void triit(int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j) {
      if (j == 0)
	pascal[i][j] = 1;
      else if (j == i)
	pascal[i][j] = 1;
      else
	pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  return;
}

int bit(int n) {
  int cnt = 0;
  for (int i = 0; i < 31; ++i) {
    if ((1 << i) & n)
      cnt = i;
  }
  return cnt;
}
int main() {
  triit(N);
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);
    ans.clear();
    int cnt = bit(n), ht, l = 0;
    ht = cnt;
    while (ht + (1 << ht) < n) {
      if (l)
	for (int i = 0; i <= ht; ++i)
	  ans.push_back({ht, i});
      else
	for (int i = ht; i >= 0; --i)
	  ans.push_back({ht, i});
      l = 1 - l;
      n = n - (1 << ht);
      ht--;
    }
    while (ht + (1 << ht) > n) {
      if (l)
	ans.push_back({ht, 0});
      else
	ans.push_back({ht, ht});
      ht--;
    }
    
    if (ht + (1 << ht) == n) {
      if (l)
	for (int i = 0; i <= ht; ++i)
	  ans.push_back({ht, i});
      else
	for (int i = ht; i >= 0; --i)
	  ans.push_back({ht, i});
      ht--;
      while (ht >= 0) {
	if (l)
	  ans.push_back({ht, 0});
	else
	  ans.push_back({ht, ht});
	ht--;
      }
      n = 0;
    }
    if (n) {
      if (l)
	ans.push_back({ht, 0});
      else
	ans.push_back({ht, ht});
      n--;
      ht--;
    }
    while (ht >= 0) {
      if (l)
	for (int i = 0; i <= ht; ++i)
	  ans.push_back({ht, i});
      else
	for (int i = ht; i >= 0; --i)
	  ans.push_back({ht, i});
      l = 1 - l;
      n -= (1 << ht);
      ht--;
    }
    ht = cnt + 1;
    while (n > 0) {
      ans.push_front({ht, ht});
      n--;
      ht++;
    }
    reverse(ans.begin(), ans.end());
    printf("Case #%d:\n", q + 1);
    ll s = 0;
    for (auto it : ans) {
      printf("%d %d\n", it.first + 1, it.second + 1);
      s += pascal[it.first][it.second];
    }
    cout<<s<<endl;
  }
  return 0;
}
