#include <iostream>

using namespace std;

int ans[505][505];

int main() {

	int r, c;
	scanf("%d%d", &r, &c);
	if (r == 1 || c == 1) {
		if (r == 1 && c == 1)
			ans[0][0] = 0;
		else {
			if (r == 1)
				for (int i = 0; i < c; ++i)
					ans[0][i] = i + 2;
			else
				for (int i = 0; i < r; ++i)
					ans[i][0] = i + 2;
		}
	}
	else {
		int cnt = 0;
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < r; ++j)
				ans[j][i] = i + 2;
		for (int i = 1; i < r; ++i)
			for (int j = 0; j < c; ++j)
				ans[i][j] *= (c + 1 + i);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}
