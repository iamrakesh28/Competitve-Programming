#include <iostream>
#include <cassert>

using namespace std;

const int seq[] = {
  0b1, 0b11, 0b10, 0b110, 0b111, 0b101, 0b100,
  0b1100, 0b1101, 0b1111, 0b1110, 0b1010, 0b1011, 0b1001, 0b1000
};
const int side[] = {0b1, 0b11, 0b10};

const int N = 205;
int tiles[N][N];

int qresult[16];


/*
  0 -> /
  1 -> \
 */

int find_pos(int bit) {
  
  int pos = 3;
  for (int i = 0; i < 4; ++i) {
    if (bit & (1 << i)) {
      pos = i;
      break;
    }
  }

  return pos;
}

void query_single(int i, int j, int pos, int cnt) {

  int r, c;

  if (pos < 2) {
    r = i, c = j + pos;
  }
  else {
    r = i + 1, c = j + pos - 2;
  }

  printf("1 %d %d\n", r + 1, c + 1);
  fflush(stdout);

  int z;
  scanf("%d", &z);
  qresult[seq[cnt]] = z;

  return;
}

void query_2x2(int i, int j) {

  int prev = 0;
  for (int cnt = 0; cnt < 15; ++cnt) {

    int bit = seq[cnt] ^ prev, pos;
    pos = find_pos(bit);

    query_single(i, j, pos, cnt);
    prev = seq[cnt];
  }

  return;
}

/*
  0 -> /
  1 -> \
 */

void solve_2x2(int r, int c, int &k) {

  int config, one = 0b1, found = -1;

  // special case
  for (int i = 1; i < 16; ++i) {
    if (abs(qresult[i] - qresult[i ^ one]) < 2)
      continue;
    if (qresult[i] > qresult[i ^ one])
      found = i & 1;
    else
      found = (i ^ one) & 1;
    break;
  }
  
  for (int i = 1; i < 16; ++i) {
    if (qresult[i] == qresult[i ^ one])
      continue;
    if (qresult[i] > qresult[i ^ one]) {
      if (found == (i & 1))
        continue;
      config = i;
    }
    else {
      if (found == ((i ^ one) & 1))
        continue;
      config = i ^ one;
    }
    break;
  }

  // cout << config << endl;
  k = qresult[0b1000];
  int change = 8 ^ config;

  tiles[r][c] = tiles[r + 1][c + 1] = 0;
  tiles[r][c + 1] = tiles[r + 1][c] = 1;

  for (int i = 0; i < 4; ++i) {
    if (i >= 2) {
      if (change & (1 << i))
        tiles[r + 1][c + i - 2] = 1 - tiles[r + 1][c + i - 2];
    }
    else {
      if (change & (1 << i))
        tiles[r][c + i] = 1 - tiles[r][c + i];
    }
  }
  
}

void query_tile(int i, int j, int &k) {

  tiles[i][j] = 1 - tiles[i][j];
  printf("1 %d %d\n", i + 1, j + 1);
  fflush(stdout);
  scanf("%d", &k);
  
  return;
}

void solve_main(int n, int &k) {
  
  n = n >> 1;
  n = n << 1;
  
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {

      if (i == 0 && j) {
        if (tiles[i][j - 1] == 0 && tiles[i + 1][j - 1] == 1) {
          query_tile(i, j - 1, k);
        }
      }
      else if (i && j == 0) {
        if (tiles[i - 1][j] == 0 && tiles[i - 1][j + 1] == 1) {
          query_tile(i - 1, j, k);
        }
      }
      else if (i && j) {
        if (
            tiles[i][j - 1] == 1 &&
            tiles[i - 1][j - 1] == 0 &&
            tiles[i - 1][j] == 1
            ) {
          query_tile(i - 1, j - 1, k);
        }
        else {
          if (
              tiles[i][j - 1] == 0 &&
              tiles[i + 1][j - 1] == 1 &&
              tiles[i - 1][j] == 0 &&
              tiles[i - 1][j + 1] == 1
              ) {
            // do nothing
            ;
          }
          else {
            if (tiles[i][j - 1] == 0 && tiles[i + 1][j - 1] == 1) { query_tile(i + 1, j - 1, k); }
            if (tiles[i - 1][j] == 0 && tiles[i - 1][j + 1] == 1) { query_tile(i - 1, j + 1, k); }
          }
        }
      }

      query_2x2(i, j);
      qresult[0] = k;
      
      solve_2x2(i, j, k);
    }
  }

  return;
}

void query_2x1(int i, int j, bool hz) {

  int prev = 0, r, c;
  for (int cnt = 0; cnt < 3; ++cnt) {

    int bit = side[cnt] ^ prev, pos;
    pos = find_pos(bit);

    if (pos) {
      if (hz == false)
        r = i + 1, c = j;
      else
        r = i, c = j + 1;
      
      printf("1 %d %d\n", r + 1, c + 1);
      fflush(stdout);

      int z;
      scanf("%d", &z);
      qresult[side[cnt]] = z;
    }
    else {

      r = i, c = j;
            
      printf("1 %d %d\n", r + 1, c + 1);
      fflush(stdout);

      int z;
      scanf("%d", &z);
      qresult[side[cnt]] = z;
    }
    prev = side[cnt];
  }

  return;
}

/*
  0 -> /
  1 -> \
 */

void solve_2x1(int r, int c, int &k, bool hz) {

  int config = 0, maxk = qresult[0];
  for (int i = 1; i < 4; ++i) {
    if (qresult[i] > maxk) {
      config = i;
      maxk = qresult[i];
    }
  }

  k = qresult[0b10];
  int change = 2 ^ config;
  tiles[r][c] = 1;

  int rs = r, cs = c;
  if (hz)
    cs ++;
  else
    rs ++;
  
  tiles[rs][cs] = 0;

  for (int i = 0; i < 2; ++i) {
    if (i) {
      if (change & (1 << i))
        tiles[rs][cs] = 1 - tiles[rs][cs];
    }
    else {
      if (change & (1 << i))
        tiles[r][c] = 1 - tiles[r][c];
    }
  }
  
}

/*
  0 -> /
  1 -> \
 */

void solve_side(int n, int &k) {

  int row_col = n >> 1;
  row_col = row_col << 1;

  for (int i = 0; i < row_col; i += 2) {
    if (tiles[i][n - 2] != 0) { query_tile(i, n - 2, k); }

    if (tiles[i + 1][n - 2] != 1) { query_tile(i + 1, n - 2, k); }

    qresult[0] = k;
    query_2x1(i, n - 1, false);
    solve_2x1(i, n - 1, k, false);
  }

  for (int i = 0; i < row_col; i += 2) {
    if (tiles[n - 2][i] != 0) { query_tile(n - 2, i, k); }

    if (tiles[n - 2][i + 1] != 1) { query_tile(n - 2, i + 1, k); }

    qresult[0] = k;
    query_2x1(n - 1, i, true);
    solve_2x1(n - 1, i, k, true);
  }

  // solve corner
  
  if (tiles[n - 2][n - 2] != 0) { query_tile(n - 2, n - 2, k); }
  
  if (tiles[n - 2][n - 1] != 1) { query_tile(n - 2, n - 1, k); }

  if (tiles[n - 1][n - 2] != 1) { query_tile(n - 1, n - 2, k); }

  int z;
  printf("1 %d %d\n", n, n);
  fflush(stdout);

  scanf("%d", &z);

  if (z > k)
    tiles[n - 1][n - 1] = 0;
  else
    tiles[n - 1][n - 1] = 1;

  return;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);

    // tiles[0][0] = tiles[1][1] = 0;
    // tiles[1][0] = 1;
    // tiles[0][1] = 1;
    solve_main(n, k);

    if (n & 1)
      solve_side(n, k);

    puts("2");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%d ", tiles[i][j]);
      }
      puts("");
    }
    fflush(stdout);

    int verdict;
    scanf("%d", &verdict);

    if (verdict == -1)
      return 0;
  }
  
  return 0;
}
