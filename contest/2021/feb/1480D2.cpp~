#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int a[N];
vector <int> a0, a1;
vector <pair <int, int>> freq;

int main() {

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);

  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      freq.push_back({a[i - 1], cnt});
      cnt = 1;
    }
    else
      cnt++;
  }

  freq.push_back({a[n - 1], cnt});

  for (int i = 0; i < freq.size(); ++i) {

    if (freq[i].second > 1) {
      a0.push_back(freq[i].first);
      if (a1.size() > 0) {
        if (a1[a1.size() - 1] != freq[i].first)
          a1.push_back(freq[i].first);
      }
      else
        a1.push_back(freq[i].first);

      continue;
    }

    if (i == freq.size() - 1) {
      a0.push_back(freq[i].first);
      continue;
    }

    if (i == 0) {
      a0.push_back(freq[i].first);
      continue;
    }

    int next = freq[i + 1].first;
    int prev = a0[a0.size() - 1];
    if (next == prev) {
      a0.push_back(freq[i].first);
      continue;
    }

    if (a1.size() > 0) {
      if (a1[a1.size() - 1] == freq[i].first)
        a0.push_back(freq[i].first);
      else
        a1.push_back(freq[i].first);
    }
    else {
      a1.push_back(freq[i].first);
    }
  }
  
  printf("%d\n", a0.size() + a1.size());
  return 0;
}
