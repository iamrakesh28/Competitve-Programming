#include <iostream>

using namespace std;

const int N = 1e5;
int skill[N][6];

bool match(int i, int j) {

	for (int a = 1; a <= skill[i][0]; ++a) {
		bool found = false;
		for (int b = 1; b <= skill[j][0]; ++b)
			if (skill[i][a] == skill[j][b]) {
				found = true;
				break;
			}
		if (found == false)
			return true;
	}
	return false;
}

int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, s;
		scanf("%d%d", &n, &s);
		for (int j = 0; j < n; ++j) {
			scanf("%d", skill[j]);
			//cout<<skill[j][0]<<endl;
			for (int v = 1; v <= skill[j][0]; ++v)
				scanf("%d", skill[j] + v);
		}
		int pairs = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (j == k)
					continue;
				if (match(j, k))
					pairs++;// cout<<j<<" "<<k<<endl;
			}
		}
		printf("Case #%d: %d\n", i + 1, pairs);
	}
	return 0;
}
