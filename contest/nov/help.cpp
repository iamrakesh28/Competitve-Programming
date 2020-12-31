#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
vector <string> num;

bool compare(string &a, string &b) {
  string ab = a + b;
  string ba = b + a;
  return ab.compare(ba) > 0 ? 1 : 0;
}

int main() {
  int n;
  cin >> n;
  num.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num.begin(), num.end(), compare);
  for (int i = 0; i < n; ++i)
    cout << num[i];
  cout << endl;
  return 0;
}
