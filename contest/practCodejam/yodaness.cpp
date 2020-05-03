#include <iostream>
#include <vector>
#include <map>

typedef long long ll;
using namespace std;

const int N = 3e4;
struct BIT {
  int n;
  vector <int> bit;
  BIT (int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  void reset(int n) {
    this->n = n;
    //bit.resize(n);
    bit.assign(n, 0);
  }
  
  int getsum(int x) {
    int ret = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
      ret += bit[x];
    return ret;
  }

  void update(int x, int delta) {
    for (; x < n; x = x | (x + 1))
      bit[x] += delta;
  }
} bit(N);

string jum[N];
map <string, int> mp;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin>>q;
  while (q--) {
    int n;
    ll ans = 0;
    cin>>n;
    bit.reset(n);
    mp.clear();
    for (int i = 0; i < n; ++i)
      cin>>jum[i];
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mp.insert({s, i});
    }
    for (int i = 0; i < n; ++i) {
      int ind = mp.at(jum[i]);
      bit.update(ind, 1);
      int sum = bit.getsum(ind - 1);
      ans = ans + ind - sum;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
