#include <iostream>
#include <vector>
#include <set>

using namespace std;

void init(set <int> &stock, vector <int> &b, int n) {
  for (int i = 1; i <= (n << 1); ++i)
    stock.insert(i);

  for (int i = 0; i < n; ++i) {
    set <int> :: iterator it = stock.find(b[i]);
    if (it != stock.end())
      stock.erase(it);
  }
}

int main() {
  int t;
  scanf("%d", &t);

  vector <int> b;
  vector <bool> x, nx;
  set <int> stock;

  while (t--) {
    int n;
    scanf("%d", &n);

    b.resize(n);
    x.resize(n);
    nx.resize(n);
    
    for (int i = 0; i < n; ++i) {
      int bi;
      scanf("%d", &bi);
      b[i] = bi;
      x[i] = nx[i] = false;
    }

    stock.clear();
    init(stock, b, n);
    
    for (int i = 0; i < n; ++i) {

      set <int> :: iterator it;

      while (stock.size() > 0 && *stock.begin() < b[i])
        stock.erase(stock.begin());

      if (stock.size() > 0) {
        x[i] = true;
        stock.erase(stock.begin());
      }
      else
        break;
    }
    
    stock.clear();
    init(stock, b, n);
    for (int i = n - 1; i >= 0; --i) {
      
      set <int> :: iterator it;

      while (stock.size() > 0) {
        it = stock.end();
        it--;
        if (*it > b[i])
          stock.erase(it);
        else
          break;
      }

      if (stock.size() > 0) {
        nx[i] = true;
        it = stock.end();
        it--;
        stock.erase(it);
      }
      else
        break;
    }

    int cnt = 0;

    /*
    for (int i = 0; i < n; ++i)
      cout << x[i] << " ";
    cout << endl;

    for (int i = 0; i < n; ++i)
      cout << nx[i] << " ";
    cout << endl;
    */
    
    for (int i = 0; i <= n; ++i) {
      if (i == 0) 
        cnt = (nx[i] ? cnt + 1 : cnt);
      else if (i == n)
        cnt = (x[i - 1] ? cnt + 1 : cnt);
      else
        cnt = (x[i - 1] && nx[i] ? cnt + 1 : cnt);
    }
    
    printf("%d\n", cnt);
  }
  
  return 0;
}
