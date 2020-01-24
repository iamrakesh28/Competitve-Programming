#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, c;
	cin>>n>>k;
	set <int> s;
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		cin>>c;
		if (s.find(c) != s.end())
			continue;
		if (s.size() < k) {
			s.insert(c);
			q.push(c);
			continue;
		}
		s.insert(c);
		q.push(c);
		auto it = q.front();
		q.pop();
		s.erase(it);
	}
	//printf("%d\n", s.size());
	cout<<s.size()<<"\n";
	int j = s.size();
	vector <int> v;
	for (int i = 0; i < j; ++i) {
		v.push_back(q.front());
		q.pop();
	}
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		cout<<*it<<" ";
	//puts("");
	cout<<"\n";
	return 0;
}
