#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		long long c, m, x, team, v, d;
		cin>>c>>m>>x;
		team = min(c, m);
		team = min(team, x);
		c = c - team;
		x = x - team;
		m = m - team;
		if (c == 0 || m == 0) {
			cout<<team<<endl;
			continue;
		}
		d = min(c, m);
		v = c - d + m - d;
		if (v >= d) {
			team += d;
			cout<<team<<endl;
			continue;
		}
		d = d - v;
		team = team + v;
		team = team + (2 * d) / 3;
		cout<<team<<endl;
	}
	return 0;
}
