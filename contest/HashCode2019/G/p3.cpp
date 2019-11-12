#include <bits/stdc++.h>

using namespace std;

char mat[16][16];
char cop[16][16];
int r, c;

bool fill(int i, int j, char ch)
{
	if (ch == 'H') {
		for (int k = j; k < c; ++k) {
			if (cop[i][k] == '.')
				cop[i][k] = 'H';
			else if (cop[i][k] == '#') {
				//cout<<c<<k<<endl;
				return false;
			}
			else
				break;
		}
		for (int k = j-1; k >= 0; --k) {
			if (cop[i][k] == '.')
				cop[i][k] = 'H';
			else if (cop[i][k] == '#')
				return false;
			else
				break;
		}
	}
	else {
		for (int k = i; k < r; ++k) {
			if (cop[k][j] == '.')
				cop[k][j] = 'V';
			else if (cop[k][j] == '#')
				return false;
			else
				break;
		}
		for (int k = i-1; k >= 0; --k) {
			if (cop[k][j] == '.')
				cop[k][j] = 'V';
			else if (cop[k][j] == '#')
				return false;
			else
				break;
		}
	}
	return true;
}

void unfill(int i, int j, char ch)
{
	if (ch == 'H') {
		for (int k = j; k < c; ++k) {
			if (cop[i][k] == 'H')
				cop[i][k] = '.';
			else
				break;
		}
		for (int k = j-1; k >= 0; --k) {
			if (cop[i][k] == 'H')
				cop[i][k] = '.';
			else
				break;
		}
	}
	else {
		for (int k = i; k < r; ++k) {
			if (cop[k][j] == 'V')
				cop[k][j] = '.';
			else
				break;
		}
		for (int k = i-1; k >= 0; --k) {
			if (cop[k][j] == 'V')
				cop[k][j] = '.';
			else
				break;
		}
	}
	return ;
}

void print()
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
		cout<<cop[i][j];
		cout<<endl;
	}
}

bool solve(int i, int j, int move)
{
	bool pos = false;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (cop[i][j] == '.') {
				//cop[i][j] == 'H';
				if (fill(i, j, 'H')) {
					pos = solve(i,j,abs(move-1));
					unfill(i, j, 'H');
					if (!pos)
						return !pos;
				}
				//cop[i][j] == 'V';
				unfill(i, j, 'H');
				if (fill(i, j, 'V') ) {
			
					pos = solve(i,j,abs(move-1));
					unfill(i, j, 'V');
					if (!pos)
						return !pos;
				}
				unfill(i, j, 'V');
			}
		}
	}
	//if (pos == false && move == 1)
		//return true;
		
	return false;
}

int main()
{
	int q;
	scanf("%d",&q);
	for (int m = 0;m < q; ++m) {
		scanf("%d%d", &r, &c);
		for (int j = 0; j < r; ++j) {
			scanf("%s", mat[j]);
			for (int k = 0; k < c; ++k)
				cop[j][k] = mat[j][k];
		}
		//print();
		int cnt = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				bool pos = false;
				if (cop[i][j] == '.') {
					//cop[i][j] = 'H';
					if (fill(i, j, 'H')) {
						//print();
						//cout<<m+1<<endl;
						pos = solve(i,j,1);
						unfill(i, j, 'H');
						//cout<<cop[i]<<endl;
						//print();
						if (!pos) {
							cnt++;
							//cout<<i<<" "<<j<<endl;
						}
					}
					//print();
					unfill(i, j, 'H');
					//cop[i][j] = 'V';
					if (fill(i, j, 'V')) {
						//cout<<cop[i]<<endl;
						//print();
						//cout<<m+1<<endl;
						pos = solve(i,j,1);
						unfill(i, j, 'V');
						//cout<<cop[i]<<endl;
						//print();
						if (!pos) {
							cnt++;		
							//cout<<i<<" "<<j<<endl;
						}
					}
					unfill(i, j, 'V');
				}
			}
		}
	printf("Case #%d: %d\n",m + 1, cnt);
	}
	return 0;
}
