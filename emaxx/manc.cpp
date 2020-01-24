#include <iostream>

using namespace std;

const int nm = 4;
int mat[nm][nm];

bool check() {
	int v1 = 0;
	for (int j = 0; j < nm; ++j)
		v1 = v1 ^ mat[0][j];
	for (int i = 1; i < nm; ++i) {
		int v2 = 0;
		for (int j = 0; j < nm; ++j)
			v2 = v2 ^ mat[i][j];
		if (v1 != v2)
			return false;
	}
	for (int i = 0; i < nm; ++i) {
		int v2 = 0;
		for (int j = 0; j < nm; ++j)
			v2 = v2 ^ mat[j][i];
		if (v1 != v2)
			return false;
	}
	//cout<<v1<<endl;
	return true;
}

bool perm(int i, int j, int mask) {
	if (i == nm)
		return check();
	if (j == nm)
		return perm(i + 1, 0, mask);
	for (int n = nm * nm - 1; n >= 0; --n) {
		if (mask & (1 << n))
			continue;
		mat[i][j] = n;
		if (perm(i, j + 1, mask | (1 << n)))
			return true;
	}
	return false;
}

int main() {

	bool val = perm(0, 0, 0);
	for (int i = 0; i < nm; ++i) {
		for (int j = 0; j < nm; ++j)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
