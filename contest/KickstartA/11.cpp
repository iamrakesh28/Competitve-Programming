#include <bits/stdc++.h>

using namespace std;

char ins[100000];

bool finD(vector< pair <int,int> > &q, int r, int c) {

	for (auto it : q) {
		if (it.first == r && it.second == c)
			return true;
	}
	return false;
}
int main() {
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, r, c, sr, sc;
		scanf("%d%d%d%d%d%d", &n, &r, &c, &sr, &sc);
		scanf("%s", ins);
		vector< pair <int,int> > q;
		q.push_back(make_pair(sr, sc));
		int m = sr, y = sc;
		for (int j = 0; j < n; ++j) {
			switch(ins[j]) {
				case 'N' : m--; break;
				case 'S' : m++; break;
				case 'E' : y++; break;
				default : y--;
			}
			//cout<<m<<" "<<y<<endl;
			while (finD(q, m, y)) {
				//cout<<"hi";
				switch(ins[j]) {
					case 'N' : m--; break;
					case 'S' : m++; break;
					case 'E' : y++; break;
					default : y--;
				}	
			}
			q.push_back({m, y});
			//cout<<q[j].first<<" "<<q[j].second<<endl;
		}
		printf("Case #%d: %d %d\n", i + 1, m, y);
	}
	return 0;
}
