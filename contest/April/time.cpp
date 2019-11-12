#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	vector <int> A, B;
	scanf("%d%d",&n, &k);
	for (int i = 0; i < 2* n; ++i) {
		int d;
		scanf("%d",&d);
		if (i % 2 == 0)
			A.push_back(i+1);
		else
			B.push_back(i+1);
	}
	for (int i = 0; i <  n; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
	for (int i = 0; i <  n; ++i)
		cout<<B[i]<<" ";
	cout<<endl;
	return 0;
}
