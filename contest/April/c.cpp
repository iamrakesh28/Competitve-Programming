#include <iostream>
#include <cstring>

using namespace std;

const int N = 2000005;
char s[N];
int w[8][N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		long long ans;
		scanf("%s", s);
		int n = strlen(s);
		int x = 0, y = 0, X, Y;
		for (int i = 0; i < n; ++i) {
			switch(s[i]) {
				case 'W' : y++; break;
				case 'S' : y--; break;
				case 'D' : x++; break;
				default : x--;
			}
			if (i) {
				w[0][i] = max(y, w[0][i - 1]);
				w[1][i] = min(y, w[1][i - 1]);
				w[2][i] = max(x, w[2][i - 1]);
				w[3][i] = min(x, w[3][i - 1]);
			}
			else {
				w[0][i] = max(y, 0);
				w[1][i] = min(y, 0);
				w[2][i] = max(x, 0);
				w[3][i] = min(x, 0);
			}
		}
		X = x, Y = y;
		x = 0, y = 0;
		ans = (abs(w[0][n - 1]) + 1 + abs(w[1][n - 1])) * (abs(w[2][n - 1]) + abs(w[3][n - 1]) + 1);
		for (int i = n - 1; i >= 0; --i) {
			switch(s[i]) {
				case 'W' : y--; break;
				case 'S' : y++; break;
				case 'D' : x--; break;
				default : x++;
			}
			if (i != n - 1) {
				w[4][i] = min(y, w[4][i - 1]);
				w[5][i] = max(y, w[5][i - 1]);
				w[6][i] = min(x, w[6][i - 1]);
				w[7][i] = max(x, w[7][i - 1]);
			}
			else {
				w[4][i] = min(y, 0);
				w[5][i] = max(y, 0);
				w[6][i] = min(x, 0);
				w[7][i] = max(x, 0);
			}
		}
		int a, b, c, d;
		long long temp;
		x = 0, y = 0;
		for (int i = 0; i < n; ++i){
			
			switch(s[i]) {
				case 'W' : y++; break;
				case 'S' : y--; break;
				case 'D' : x++; break;
				default : x--;
			}
			if (i) {
				a = w[0][i - 1] + w[4][n - i - 1];
				b = w[1][i - 1] + w[5][n - i - 1];
				c = w[2][i - 1] + w[6][n - i - 1];
				d = w[3][i - 1] + w[7][n - i - 1];
				temp = (abs(a) + 1 + abs(b)) * (abs(c) + abs(c) + 1);
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
