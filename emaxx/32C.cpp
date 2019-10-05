#include <bits/stdc++.h>

using namespace std;

long long  solve(long long n, long long s)
{
	//if (s > n)
		//return n;
	if (n % s == 0)
		return n;
	return (((n / s) + 1) * (n % s));
}

int main()
{
	long long  n, m, s, row, col;
	cin>>n>>m>>s;
	row = solve(n, s);
	col = solve(m, s);
	cout<<row * col<<endl;
	return 0;
}
