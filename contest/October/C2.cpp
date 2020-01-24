#include <iostream>
#include <set>

using namespace std;

const int N = 1e5;
int arrx[N], arry[N], arrz[N];
bool rem[N];

int main() {

	int n;
	scanf("%d", &n);
	set <pair<int, pair<int, pair <int, int>>>> same[3];
	set <pair<int, <int, int>>> X;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		X.insert({x, {y, i}});
		same[0].insert({x, {y, {z, i}}});
		same[1].insert({y, {z, {x, i}}});
		same[2].insert({x, {z, {y, i}}});
		arrx[i] = x;
		arry[i] = y;
		arrz[i] = z;
		rem[i] = false;
	}
	int x, y, z, start, second;
	auto it = same[0].begin();
	while (it != same[0].end()) {
		auto t = it;
		auto it1 = ++t;
		if (it1 == same[0].end())
			break;
		if ((*it1).first == (*it).first && (*it1).second.first == (*it).second.first) {
			int a = (*it).second.second.second, b = (*it1).second.second.second;
			rem[a] = rem[b] = true;
			printf("%d %d\n", a + 1, b + 1);
			it = ++it1;
		}
		else
			it = it1;
	}

	while (it != same[1].end) {
		if ()
			same[1].erase();
	}
	auto it = same[1].begin();
	while (it != same[1].end()) {
		auto t = it;
		auto it1 = ++t;
		start = (*it).second.second.second;
		if (it1 == same[1].end())
			break;
		start = (*it1).second.second.second;
		if ((*it1).first == (*it).first && (*it1).second.first == (*it).second.first) {
			int a = (*it).second.second.second, b = (*it1).second.second.second;
			rem[(*it1).second.second.second] = rem[(*it).second.second.second] = true;
			printf("%d %d\n", a + 1, b + 1);
			it = ++it1;
		}
		else
			it = it1;
	}
	return 0;
}
