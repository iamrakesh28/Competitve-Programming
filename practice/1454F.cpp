#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map <int, vector <pair <int, int>>> mapy;
map <int, pair <int, int>> mapx, mapz;
vector <int> arr;

void preproc(int n) {

  mapx.clear();
  mapy.clear();
  mapz.clear();

  int curmax = arr[0], start = 0;
  for (int i = 1; i < n; ++i) {

    if (max(curmax, arr[i]) != curmax) {
      mapx.insert({curmax, {start, i - 1}});
      start = i;
      curmax = arr[i];
    }
  }
  mapx.insert({curmax, {start, n - 1}});

  curmax = arr[n - 1], start = n - 1;
  for (int i = n - 2; i >= 0; --i) {

    if (max(curmax, arr[i]) != curmax) {
      mapz.insert({curmax, {i + 1, start}});
      start = i;
      curmax = arr[i];
    }
  }
  mapz.insert({curmax, {0, start}});
  
  stack <pair <int, int>> st;
  vector <int> L(n), R(n);

  for (int i = 0; i < n; ++i) {

    while (st.size() && st.top().first >= arr[i])
      st.pop();

    int l = 0;
    if (st.size())
      l = st.top().second + 1;

    L[i] = l;
    st.push({arr[i], i});
  }

  while (st.size())
    st.pop();
  
  for (int i = n - 1; i >= 0; --i) {

    while (st.size() && st.top().first >= arr[i])
      st.pop();

    int r = n - 1;
    if (st.size())
      r = st.top().second - 1;

    R[i] = r;  
    st.push({arr[i], i});
  }

  for (int i = 0; i < n; ++i) {
    if (mapy.find(arr[i]) == mapy.end())
      mapy.insert({arr[i], vector <pair <int, int>> {{L[i], R[i]}}});
    else
      mapy[arr[i]].push_back({L[i], R[i]});
  }

  return ;
}

bool possible(
              pair <int, int> &x,
              pair <int, int> &y,
              pair <int, int> &z,
              int n
              ) {

  int yl, yr;
  yl = max(y.first, x.first + 1);
  yr = min(y.second, z.second - 1);

  cout << "------------------------------\n";
  cout << x.first << " " << x.second << endl;
  cout << y.first << " " << y.second << endl;
  cout << z.first << " " << z.second << endl;
  cout << yl << " " << yr << endl;
  
  if (
      yl <= x.second + 1
      && yr >= z.first - 1
      && yl >= y.first
      && yr <= y.second
      ) {
    puts("YES");
    printf("%d %d %d\n", yl, yr - yl + 1, n - yr - 1);
    return true;
  }
  
  return false;
}

bool solve(int n) {

  for (auto &vec : mapy) {
    
    pair <int, int> x = mapx.at(vec.first);
    pair <int, int> z = mapz.at(vec.first);
    
    for (auto &p : vec.second)
      if (possible(x, p, z, n))
        return true;
  }
  return false;
}


int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    arr.resize(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &arr[i]);

    preproc(n);

    /*
    for (auto it : mapx)
      cout << it.first << " " << it.second.first << " " << it.second.second << endl;

    for (auto it : mapz)
      cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    */

    /*
    for (auto vec : mapy) {
      cout << "-------------------------\n";
      cout << vec.first << endl;
      for (auto p : vec.second)
        cout << p.first << " " << p.second << endl;
    }
    */

    if (solve(n) == false)
      puts("NO");
  }
  
  return 0;
}
