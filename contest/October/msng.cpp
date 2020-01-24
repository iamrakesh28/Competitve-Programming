#include <iostream>
#include <cstring>
#include <set>
#include <cassert>

//#define debug
using namespace std;

const long long inf = 1e12 + 1;
const int N = 105;

char s[N][45];
int b[N];
set <pair<long long, int>> st;

long long decimal(int base, int id) {
  long long val = 0, power = 1;
  int len = s[id][0], v;
  for (int i = 0; i < len; ++i) {
    if (val >= inf || power >= inf)
      return inf;
    if (s[id][len - i] <= '9')
      v = s[id][len - i] - '0';
    else
      v = s[id][len - i] - 'A' + 10;
    val = val + v * power;
	if (v >= base)
		return -1;
	assert(val >= 0);
	assert(power >= 0);
    power = power * base;
  }
  if (val >= inf)
      return inf;
  return val;
}

void solve(int n) {
  for (int i = 0; i < n; ++i) {
    if (b[i] == -1) {
      for (int j = 2; j <= 36; ++j) {
		long long val = decimal(j, i);
		if (val >= inf)
	  		break;
		if (val < 0)
			continue;
		st.insert({val, i});
      }
    }
    else {
		long long val = decimal(b[i], i);
		if (val >= inf)
	  		break;
		if (val < 0)
			continue;
     	st.insert({val, i});
	}
  }
	return;
}

int main() {

  #ifdef debug
     freopen("test", "r", stdin);
  #endif
     
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    st.clear();
    long long ans = -1, val, cnt = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%s", b + i, s[i] + 1);
      s[i][0] = strlen(s[i] + 1);
		if (s[i][0] > 1)
			assert(s[i][1] != '0');
      //cout<<(s[i] + 1)<<endl;
    }
    solve(n);
	auto it = st.begin();
	if (it == st.end()) {
		puts("-1");
		assert(1);
		continue;
	}
	val = (*it).first;
	if (n == 1 && val < inf) {
		printf("%lld\n", val);
		continue;
	}
	it++;
    while (it != st.end()) {
		if ((*it).first != val) {
			val = (*it).first;
			cnt = 1;
		}
		else
			cnt++;
		if (cnt == n && val < inf) {
			ans = val;
			break;
		}
		it++;
	}
    printf("%lld\n", ans);
  }
  return 0;
}
