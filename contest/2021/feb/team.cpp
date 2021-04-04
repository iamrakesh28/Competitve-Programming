#include <iostream>
#include <set>
#include <vector>

using namespace std;
using LL = long long;

const int LETTER = 26;
int same_count[LETTER][LETTER];
set <string> letter_set[LETTER];
vector <string> s;

void initialize(int n) {

  for (int i = 0; i < LETTER; ++i) {
    letter_set[i].clear();

    for (int j = 0; j < LETTER; ++j) {
      same_count[i][j] = 0;
    }
  }

  s.resize(n);

  return;
}

void process(int n) {

  for (int i = 0; i < n; ++i) {

    string si;
    for (int j = 1; j < s[i].size(); ++j)
      si = si + s[i][j];
          
    for (int j = 0; j < LETTER; ++j) {
      if (j == s[i][0] - 'a')
        continue;
      if (letter_set[j].find(si) != letter_set[j].end())
        same_count[s[i][0] - 'a'][j]++;
    }
  }
  
  return;
}

LL solve(int n) {

  LL ways = 0;
  for (int i = 0; i < LETTER; ++i) {
    for (int j = i + 1; j < LETTER; ++j) {
      int tot1 = letter_set[i].size() - same_count[i][j];
      int tot2 = letter_set[j].size() - same_count[j][i];

      ways = ways + (LL)tot1 * tot2 * 2;
    }
  }

  return ways;
}

int main() {

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    initialize(n);

    for (int i = 0; i < n; ++i) {
      string si;
      cin >> s[i];

      for (int j = 1; j < s[i].size(); ++j)
        si = si + s[i][j];

      letter_set[s[i][0] - 'a'].insert(si);
      
    }
    process(n);
    LL ways = solve(n);

    cout << ways << endl;
  }
  
  return 0;
}
