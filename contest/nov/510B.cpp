#include <iostream>
#include <vector>
#include <string>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
     
bool cycle = 0;
     
//A -> A + 32 (on visitation, convert to lowercase)

int n, m;
     
void dfs (vector <string> &puzzle, int i, int j, int prev_i, int prev_j) {
    puzzle[i][j] += 32;
    if (i > 0) {
        if (puzzle[i - 1][j] == (puzzle[i][j] - 32)) {
            dfs(puzzle, i - 1, j, i, j);
        }
        else if (puzzle[i - 1][j] == puzzle[i][j] && (prev_i != i - 1 || prev_j != j)) {
            cycle = 1;
        }
    }
    if (j > 0) {
        if (puzzle[i][j - 1] == (puzzle[i][j] - 32)) {
            dfs(puzzle, i, j - 1, i, j);
        }
        else if (puzzle[i][j - 1] == puzzle[i][j] && (prev_i != i || prev_j != j - 1)) {
            cycle = 1;
        }
    }
    if (j < m - 1) {
        if (puzzle[i][j + 1] == (puzzle[i][j] - 32)) {
            dfs(puzzle, i, j + 1, i, j);
        }
        else if (puzzle[i][j + 1] == puzzle[i][j] && (prev_i != i || prev_j != j + 1)) {
            cycle = 1;
        }
    }
    if (i < n - 1) {
        if (puzzle[i + 1][j] == (puzzle[i][j] - 32)) {
            dfs(puzzle, i + 1, j, i, j);
        }
        else if (puzzle[i + 1][j] == puzzle[i][j] && (prev_i != i + 1 || prev_j != j)) {
            cycle = 1;
        }
    }
}
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector <string> puzzle(n);
    for (int i = 0; i < n; i++) {
        cin >> puzzle[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (puzzle[i][j] < 97) {
                dfs(puzzle, i, j, -69420, -69420);
            }
            if (cycle) {
                break;
            }
        }
        if (cycle) {
            break;
        }
    }
    cout << (cycle ? "Yes" : "No") << "\n";
    return 0;
}
