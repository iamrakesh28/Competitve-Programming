#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205;
bool stories[N][N], users[N][N],
  alpha_1[N][N], alpha_2[N][N];
int creator[N], n, m;
pair <int, int> recom[N];

bool compare(pair <int, int> &a, pair <int, int> &b) {

  if (a.first != b.first)
    return a.first > b.first;
  return a.second < b.second;
  
}

void initialize(int n, int m) {

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j)
      alpha_1[i][j] = alpha_2[i][j] = false;
  }

  for (int i = 0; i < n; ++i)
    memset(stories[i], false, sizeof(bool) * m);
    
  return;
}

void read_input() {

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int j;
    scanf("%d", &j);
    creator[i] = j - 1;
  }

  initialize(n, m);
  
  int p, q;
  scanf("%d%d", &p, &q);

  for (int i = 0; i < p; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    users[v][u] = true;
  }

  for (int i = 0; i < q; ++i) {
    int u, k;
    scanf("%d%d", &u, &k);
    u--, k--;
    stories[k][u] = true;
  }

  return;
}

void preprocess() {

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (stories[i][j])
        alpha_1[creator[i]][j] = true;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (stories[i][j] == false)
        continue;
      for (int k = 0; k < m; ++k) {
        if (stories[i][k] == false)
          continue;
        alpha_2[j][k] = true;
      }
    }
  }
  return;
}

int digest_score(int user, int story) {

  int score = 0;
  if (stories[story][user] || creator[story] == user) {
    return -1;
  }

  for (int j = 0; j < m; ++j) {
    if (j == user)
      continue;
    int a = 0, b = 0;
    if (users[j][user])
      a = 3;
    else if (alpha_1[j][user])
      a = 2;
    else if (alpha_2[j][user])
      a = 1;

    if (creator[story] == j)
      b = 2;
    else if (stories[story][j])
      b = 1;

    score += a * b;
  }

  return score;
}

int main() {

  read_input();
  preprocess();
  
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      recom[j] = {digest_score(i, j), j};
    }

    sort(recom, recom + n, compare);
    for (int j = 0; j < 3; ++j)
      printf("%d ", recom[j].second + 1);
    puts("");
  }
  
  return 0;
}

