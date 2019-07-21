// C++ Code implementation for above problem
#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

// QItem for current location and distance
// from source location
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};

int minDistance(char grid[N][M])
{
	QItem source(0, 0, 0);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == '0')
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// Finding source
			if (grid[i][j] == 's')
			{
			source.row = i;
			source.col = j;
			}
		}
	}

	// applying BFS on matrix cells starting from source
	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;
	while (!q.empty()) {
		QItem p = q.front();
		q.pop();

		// Destination found;
		if (grid[p.row][p.col] == 'd')
			return p.dist;

		// moving up
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col] == false) {
			q.push(QItem(p.row - 1, p.col, p.dist + 1));
			visited[p.row - 1][p.col] = true;
		}

		// moving down
		if (p.row + 1 < N &&
			visited[p.row + 1][p.col] == false) {
			q.push(QItem(p.row + 1, p.col, p.dist + 1));
			visited[p.row + 1][p.col] = true;
		}

		// moving left
		if (p.col - 1 >= 0 &&
			visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
		}

		// moving right
		if (p.col + 1 < M &&
			visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
		}
	}
	return -1;
}

// Driver code
int main()
{
	char grid[N][M] = { { '0', '*', '0', 's' },
						{ '*', '0', '*', '*' },
						{ '0', '*', '*', '*' },
						{ 'd', '*', '*', '*' } };

	cout << minDistance(grid);
	return 0;
}

