#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main() {
  ll n, p, w, d, g;
  bool ans = false;
  cin>>n>>p>>w>>d;
  for (int i = 0; i < w; ++i) {
    g = p - i * d;
    if (g >= 0 && g % w == 0) {
      g = g / w;
      if (g + i <= n) {
	ans = true;
	cout<<g<<" "<<i<<" "<<(n - g - i)<<"\n";
	break;
      }
    }
  }
  if (!ans)
    puts("-1");
  return 0;
}
