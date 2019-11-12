#include <iostream>

using namespace std;

char s[100005];
int room[10];

int next(char c) {
	if (c == 'R') {
		for (int i = 0; i < 10; ++i)
			if (room[10 - i - 1] == 0)
				return 10 - i - 1;
	}
	else {
		for (int i = 0; i < 10; ++i)
			if (room[i] == 0)
				return i;
	}
}
int main() {

	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < 10; ++i)
		room[i] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			room[s[i] - '0'] = 0;
		else
			room[next(s[i])] = 1;
	}
	for (int i = 0; i < 10; ++i)
		printf("%d", room[i]);
	puts("");
	return 0;
}
