#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {

	int t;
	set <int> s;
	s.insert(2);
	s.insert(3);
	for(int i = 4; i <= 1e6; ++i)
		s.insert(i);
	auto it = distance(s.find(2), s.find(1e6));
	cout<<it<<endl;
	return 0;
}
