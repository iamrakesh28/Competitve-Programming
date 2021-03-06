#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int A[N], G[N], arr[N], temp[N];
bool avail[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, pos = 1, sum = 0;
    set <pair <int, int> > s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      A[i] = G[i] = 0, avail[i] = true;
    G[n] = 0;
    for (int i = 0; i < n; ++i) {
      int num;
      scanf("%d", &num);
      arr[i] = num;
      if (num != -1)
	A[num]++;
    }
    s.clear();
    for (int i = 0; i <= n; ++i) {
      int num;
      scanf("%d", &num);
      if (num)
	s.insert({i, num}), sum += i * num;
      if (i == 0) {
	sum += num;
	int cnt = 0;
	for (int j = n - 1; j >= 0; j--) {
	  if (cnt >= num)
	    break;
	  if (A[j] == 0)
	    avail[j] = false, cnt++;
	}
      }
    }
    
    if (sum < n) {
      puts("impossible");
      continue;
    }
    int cnt = 0;
    vector <int> ans;
    for (int i = n - 1; i >= 0; i--) {
      if (A[i] == 0) {
	cnt++;
	continue;
      }
      auto it = s.lower_bound({A[i], 0});
      if (it == s.end()) {
	pos = 0;
	break;
      }
      int tow = (*it).first, freq = (*it).second;
      s.erase(it);
      for (int j = 0; j < tow - A[i]; ++j)
	ans.push_back(i);
      freq--;
      if (freq)
	s.insert({tow, freq});
    }
    if (pos == 0) {
      puts("impossible");
      continue;
    }
    
    if (s.size()) {
      for (int i = 0; i < n; ++i) {
	if (s.size() == 0)
	  break;
	if (A[i] || avail[i] == false)
	  continue;
	auto it = s.end();
	it--;
	int tow = (*it).first, freq = (*it).second - 1;
	//cout<<i<<" "<<tow<<" "<<freq<<endl;
	s.erase(it);
	for (int j = 0; j < tow - A[i]; ++j)
	  ans.push_back(i);
	if (freq)
	  s.insert({tow, freq});
      }
    }
    //if (s.size()) {
    //  puts("impossible");
    //  continue;
    //}
    //cout<<sum<<endl;
    int j = 0;
    sort(ans.begin(), ans.end());

    for (int i = 0; i < n; ++i) {
      if (arr[i] != -1)
	temp[i] = arr[i];
      else
	temp[i] = ans[j++];
    }
    for (int i = 0; i < n; ++i)
      A[i] = 0;
    for (int i = 0; i < n; ++i)
      A[temp[i]] = 1;
    for (int i = 0; i < n; ++i) {
      if (A[i] == 1 && avail[i] == true || A[i] == 0 && avail[i] == false)
	continue;
      else {
	pos = 0;
	break;
      }
    }

    if (pos == 0) {
      puts("impossible");
      continue;
    }
    
    for (int i = 0; i < n; ++i)
      printf("%d ", temp[i]);
    puts("");
  }
  return 0;
}
