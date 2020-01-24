#include <iostream>
#include <set>

using namespace std;

int main() {

	char ch;
	int win = 0;
	set <int> s;
	while ((ch = getchar()) != '\n') {
		if (s.empty()) {
			puts("Mike");
			s.insert(ch - 'a');
			continue;
		}
		if (*s.begin() < (ch - 'a')) {
			puts("Ann");
			s.insert(ch - 'a');
			continue;
		}
		puts("Mike");
		s.insert(ch - 'a');
	}
	return 0;
}
