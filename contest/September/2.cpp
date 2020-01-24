#include <iostream>

char mat[105][105];

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			mat[i][j] = 'B';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2)
				mat[i][j] = 'W';
			/*			
			if (mat[i][j] == 'W')
				continue;
			if (j + 2 < n) {
				if (i > 0)
					mat[i - 1][j + 2] = 'W';
				if (i + 1 < n)
					mat[i + 1][j + 2] = 'W';
			}
			if (i + 2 < n) {
				if (j + 1 < n)
					mat[i + 2][j + 1] = 'W';
				if (j > 0)
					mat[i + 2][j - 1] = 'W';
			}
			*/
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout<<mat[i][j];
		cout<<endl;
	}
	return 0;
}
