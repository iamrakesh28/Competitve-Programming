#include <iostream>

using namespace std;

int solvef(int f, int cnts, int cntw, int s, int w) {
  int ans = 0;
  if (s < w) {
    int amt = f / s;
    amt = min(amt, cnts);
    //cout << ": "<< f << " "<< s;
    f   = f - amt * s;
    ans = amt;
    amt = f / w;
    amt = min(amt, cntw);
    //cout << " " << amt << endl; 
    ans = ans + amt;
  }
  else {
    int amt = f / w;
    amt = min(amt, cntw);
    f   = f - amt * w;
    ans = amt;
    amt = f / s;
    amt = min(amt, cnts);
    ans = ans + amt;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int p, f, cnts, cntw, s, w;
    scanf("%d%d", &p, &f);
    scanf("%d%d", &cnts, &cntw);
    scanf("%d%d", &s, &w);
    int ans = 0;
    // p
    for (int i = 0; i <= cnts; ++i) {
      long long temp = (long long)i * s;
      //cout << i << " " << temp << " " ;
      if (temp <= p) {
	int val = p;
	val = val - temp;
	int j = val / w;
	j = min(j, cntw);
	//cout << j << " ";
	int cur = i + j + solvef(f, cnts - i, cntw - j, s, w);
	//cout << cur << endl;
	ans = max(ans, cur);
      }
      else
	break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
