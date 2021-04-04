#include <iostream>
#include <cstring>

using namespace std;

const int R = 6, C = 7;
char grid[R + 5][C + 6];
int ind[C];

int winner() {

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j <= C - 4; ++j) {
      bool found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i][j + k] != 'R')
          found = false;
      }

      if (found)
        return 0;

      found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i][j + k] != 'Y')
          found = false;
      }
      
      if (found)
        return 1;
    }
  }

  for (int j = 0; j < C; ++j) {
    
    for (int i = 0; i <= R - 4; ++i) {
      bool found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i + k][j] != 'R')
          found = false;
      }

      if (found)
        return 0;

      found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i + k][j] != 'Y')
          found = false;
      }
      
      if (found)
        return 1;
    }
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      bool found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i + k][j + k] != 'R') {
          found = false;
          break;
        }
      }

      if (found)
        return 0;

      found = true;
      for (int k = 0; k < 4; ++k) {
        if (grid[i + k][j + k] != 'Y') {
          found = false;
          break;
        }
      }

      if (found)
        return 1;

      found = true;
      for (int k = 0; k < 4; ++k) {
        if (j < k) {
          found = false;
          break;
        }
        if (grid[i + k][j - k] != 'R') {
          found = false;
          break;
        }
      }

      if (found)
        return 0;

      found = true;
      for (int k = 0; k < 4; ++k) {
        if (j < k) {
          found = false;
          break;
        }
        if (grid[i + k][j - k] != 'Y') {
          found = false;
          break;
        }
      }

      if (found)
        return 1;
    }
  }
  
  return -1;
}

int main() {

  int move = 0, cnt = 0;
  memset(grid, '_', sizeof(grid));
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < R; ++j) {
      int col;
      scanf("%d", &col);

      cnt ++;
      char ch;
      if (move == 0)
        ch = 'R';
      else
        ch = 'Y';
      
      grid[R - 1 - ind[col - 1]++][col - 1] = ch;
      move = (move + 1) % 2;
      int win = winner();
      if (win == 0) {
        printf("RED %d\n", cnt);
        return 0;
      }
      else if (win == 1) {
        printf("YELLOW %d\n", cnt);
        return 0;
      }
    }
  }
  puts("DRAW");
  return 0;
}
