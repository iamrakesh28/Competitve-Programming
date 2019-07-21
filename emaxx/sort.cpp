#include <bits/stdc++.h>

using namespace std;

int main() {
	
	pair <int, pair <int, int>> edge[3];
	edge[0].first = 10;
	edge[0].second.first = 0;
	edge[0].second.second = 2;
	edge[1].first = 10;
	edge[1].second.first = 0;
	edge[1].second.second = 2;
	edge[2].first = 10;
	edge[2].second.first = 0;
	edge[2].second.second = 3;
	sort(edge, edge + 3);
	for (int i = 0; i < 3; ++i) {
		cout<<edge[i].first<<"\t"<<edge[i].second.first<<"\t"<<edge[i].second.second<<endl;
	}
}
