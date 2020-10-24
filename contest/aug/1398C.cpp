#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 5;
char s[N];
map <int, int> st;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    st.clear();
    int n, sum = 0;
    long long cnt = 0;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
      int val = s[i] - '0';
      sum += val;
      if (st.find(sum - i - 1) != st.end())
	st[sum - i - 1]++;
      else
	st[sum - i - 1] = 1;
      //cout << sum - i - 1 << " ";
    }
    // continue;
    sum = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
      int val = s[i] - '0';
      //temp++;
      temp = sum - i;
      if (st.find(temp) != st.end())
	cnt += st[temp];
      //cout << temp << " " << st.count(-temp) << endl;
      sum += val;
      st[sum - i - 1]--;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
