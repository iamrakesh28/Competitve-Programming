#include <iostream>

using namespace std;

int main() {
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  for (int i = 0; i < t; ++i) {
    string s, ans = "";
    cin>>s;
    int cur = 0;
    for (char ch : s) {
      int val = ch - '0';
      if (cur <= val) {
	while (cur < val) {
	  ans = ans + '(';
	  cur++;
	}
	ans = ans + ch;
      }
      else {
	while (cur > val) {
	  ans = ans + ')';
	  cur--;
	}
	ans = ans + ch;
      }
    }
    while (cur > 0) {
      ans = ans + ')';
      cur--;
    }
    cout<<"Case #"<<i + 1<<": "<<ans<<"\n";
  }
  return 0;
}
