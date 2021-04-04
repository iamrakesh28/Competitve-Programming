#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
int visit[N], max_len;
vector <int> cycle, order;

void assignment(vector <int> &a, vector <int> &b) {

  int len = b.size();
  a.resize(len);
  for (int i = 0; i < b.size(); ++i)
    a[i] = b[i];

  return;
}

void dfs(int u, vector <int> &alumniID) {

  visit[u] = 1;
  int next = alumniID[u] - 1;
  if (visit[next] == 2) {
    visit[u] = 2;
    return;
  }
  
  if (visit[next] == 1) {
    // cycle found
    vector <int> temp;
    temp.push_back(u);
    for (int i = order.size() - 1; i >= 0; i--) {

      temp.push_back(order[i]);
      if (order[i] == next)
        break;
    }
    int len = temp.size();
    sort(temp.begin(), temp.end());
    
    if (len > max_len) {
      assignment(cycle, temp);
    }
    else if (len == max_len) {
      bool _swap = false;
      for (int i = 0; i < len; ++i) {
        if (cycle[i] > temp[i]) {
          _swap = true;
          break;
        }
      }

      if (_swap)
        assignment(cycle, temp);
    }
  }
  else {
    order.push_back(u);
    dfs(next, alumniID);
    order.pop_back();
  }

  visit[u] = 2;

  return;
}

vector <int> idsOfAlumni (vector <int> &alumniID) {

  int n = alumniID.size();
  memset(visit, 0, sizeof(int) * n);
  max_len = 0;
  cycle.clear();
  order.clear();

  for (int i = 0; i < n; ++i) {

    if (visit[i] == 0)
      dfs(i, alumniID);
  }

  return cycle;
}

int main() {

  vector <int> alumniID{2, 3, 4, 1};
  vector <int> ids = idsOfAlumni(alumniID);

  for (int id : ids) {
    cout << id + 1 << " ";
  }
  cout << endl;
  
  return 0;
}
