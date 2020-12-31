#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 5, alphabet = 26, inf = 1e8;

string person[N];
bool pres_alph[alphabet];
int dp[alphabet][alphabet];

void floyd() {
  for (int k = 0; k < alphabet; ++k)
    for (int i = 0; i < alphabet; i++)
      for (int j = 0; j < alphabet; ++j)
	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  return;
}

int main() {
  int t;
  cin >> t;
  for (int h = 0; h < t; ++h) {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < alphabet; ++i)
      for (int j = 0; j < alphabet; ++j)
	dp[i][j] = inf;
    
    for (int i = 0; i < n; ++i) {
      cin >> person[i];
      memset(pres_alph, false, sizeof pres_alph);
      
      for (int j = 0; j < person[i].length(); ++j)
	pres_alph[person[i][j] - 'A'] = true;
      for (int j = 0; j < alphabet; j++) {
	dp[j][j] = 0;
	if (pres_alph[j] == false)
	  continue;
	for (int k = j + 1; k < alphabet; ++k) {
	  if (pres_alph[k] == false)
	    continue;
	  dp[j][k] = 1;
	  dp[k][j] = 1;
	}
      }
    }

    floyd();
    /*
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j)
	cout << dp[i][j] << " ";
      cout << endl;
    } 
    */
    cout << "Case #" << h + 1 <<": ";
    while (q--) {
      int xi, yi, ans = inf;
      cin >> xi >> yi;
      for (int i = 0; i < person[xi - 1].length(); ++i) {
	int char_val = person[xi - 1][i] - 'A';
	for (int j = 0; j < person[yi - 1].length(); ++j)
	  ans = min(ans, dp[char_val][person[yi - 1][j] - 'A']);
      }
      if (ans >= inf)
	ans = -3;
      cout << ans + 2<< " ";
    }
    cout << endl;
  }
  return 0;
}
