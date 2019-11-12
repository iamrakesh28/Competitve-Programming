#include <iostream>
#include <cstring>

using namespace std;

char x[100005], y[100005];
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%s", x, y);
		int x_ = strlen(x);
		int y_ = strlen(y);
		int k = 0, need = 0;
		for (int i = x_ - 1, j = y_ - 1; i >= 0 && j >= 0; i--) {
			if (y[j] == '1') {
				if (x[i] == '1')
					break;
				k++;
			}
			else
				j--;
		}
		printf("%d\n", k);
	}
	return 0;
}
