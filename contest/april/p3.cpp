#include <iostream>
#include <cstring>
#include <stack>

typedef long long ll;
using namespace std;

const int inf = 1e9, N = 2e3 + 5;
char prog[N];
stack <ll> st;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, cnt = 0;
    scanf("%s", prog);
    n = strlen(prog);
    while (st.size())
      st.pop();
    ll w = 0, h = 0, mul = 1;
    st.push(mul);
    for (int i = 0; i < n; ++i) {
      if (prog[i] >= '2' && prog[i] <= '9') {
	mul = st.top();
	mul = mul * (prog[i] - '0');
	mul = mul % inf;
	st.push(mul);
	continue;
      }
      if (prog[i] == '(') {
	cnt++;
	continue;
      }
      if (prog[i] == ')') {
	cnt--;
	st.pop();
	continue;
      }
      mul = st.top();
      switch(prog[i]) {
      case 'N' : h = (h - mul + inf) % inf;
	break;
      case 'S' : h = (h + mul + inf) % inf;
	break;
      case 'E' : w = (w + mul + inf) % inf;
	break;
      default : w = (w - mul + inf) % inf;
      }
    }
    printf("Case #%d: %d %d\n", i + 1, w + 1, h + 1);
  }
  return 0;
}
