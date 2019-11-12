#include <iostream>

#define N 100005
using namespace std;

long long arr[N];
int main() {

	long long n, k, del = 0, op = 0, pos, pos2;
	int m;
	cin>>n>>m>>k;
	for (int i = 0; i < m; ++i)
		cin>>arr[i];
	int cur = 0;
	while (cur < m) {
		pos = (arr[cur] - del - 1) / k;
		int next = cur + 1;
		while (next < m) {
			pos2 = (arr[next] - del - 1) / k;
			if (pos2 != pos)
				break;
			next++;
		}
		del += next - cur;
		cur = next;
		op++;
	}
	cout<<op<<endl;
	return 0;
}
