#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char r1[N], r2[N];

/*
0 -> left
1 -> up
2 -> down
*/

int main () {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d%s%s", &n, r1, r2);
		if (n == 1) {
			if (r1[0] == '1' || r1[0] == '2')
				puts("NO");
			else if (r2[0] == '1' || r2[0] == '2')
				puts("NO");
			else
				puts("YES");
			continue;
		}
		int i, j;
		i = 1, j = n - 1;
		bool ans = true;
		int cur, dir;
		if (r2[j] == '1' || r2[j] == '2') {
			i = 1;
			j = n - 2;
			dir = 0;
		}
		else {
			i = 0;
			j = n - 1;
			dir = 1;
		}
		while (!(i == 0 && j == 0)) {
			//if (i == 0 && j )
			//cout<<ans<<" "<<i<<" "<<j<<" "<<dir<<endl;
			if (i == 1) {
				if (r2[j] == '1' || r2[j] == '2') {
					if (dir == 2)
						ans = false;
					else {
						i = 1;
						j--;
						dir = 0;
					}
				}
				else {
					if (dir == 2) {
						ans = true;
						i = 1;
						j--;
						dir = 0;
					}
					else {
						ans = true;
						i = 0;
						dir = 1;
					}
				}
			}
			else {
				if (r1[j] == '1' || r1[j] == '2') {
					if (dir == 1)
						ans = false;
					else {
						i = 0;
						j--;
						dir = 0;
					}
				}
				else {
					if (dir == 1) {
						ans = true;
						i = 0;
						j--;
						dir = 0;
					}
					else {
						ans = true;
						i = 1;
						dir = 2;
					}
				}
			}
			//cout<<ans<<endl;
			if (ans == false)
				break;
		}

		if (ans) {
			if (r1[0] == '1' || r1[0] == '2') {
					if (dir == 0)
						puts("YES");
					else 
						puts("NO");
				}
			else {
					if (dir == 1)
						puts("YES");
					else
					puts("NO");
				}
		}
		else
		puts("NO");
	}
	return 0;
}
