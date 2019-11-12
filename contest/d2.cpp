#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char s[200005], t[200005];
vector <int> alp[26];
pair <int, int> ran[200005];

int find(int num, int pos) {
	int beg = 0, end = alp[num].size() - 1, mid, ans = alp[num][end];
	while (beg <= end) {
		mid = (beg + end) >> 1;
		if (alp[num][mid] < pos) {
			ans = alp[num][mid];
			beg = mid + 1;
		}
		else
			end = mid - 1;
		//cout<<beg<<" "<<end<<" "<<mid<<endl;
	}
	return ans;
}

int find1(int num, int pos) {
	int beg = 0, end = alp[num].size() - 1, mid, ans = alp[num][end];
	while (beg <= end) {
		mid = (beg + end) >> 1;
		if (alp[num][mid] > pos) {
			ans = alp[num][mid];
			end = mid - 1;
		}
		else
			beg = mid + 1;
		//cout<<beg<<" "<<end<<" "<<mid<<endl;
	}
	return ans;
}

int main() {

	scanf("%s%s", s, t);
	int S = strlen(s), T = strlen(t);
	for (int i = 0; i < S; ++i)
		alp[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; ++i)
		sort(alp[i].begin(), alp[i].end());
	ran[T - 1].first = alp[t[T - 1] - 'a'][0];
	auto it = alp[t[T - 1] - 'a'].end();
	ran[T - 1].second = *(--it);
	int ans = 0, num;
	//cout<<ran[T - 1].first<<" "<<ran[T - 1].second<<endl;
	for (int i = T - 2; i >= 0; i--) {
		num = t[i] - 'a';
		ran[i].first = alp[num][0];
		it = alp[num].end();
		it--;
		if (*it >= ran[i + 1].second) {
			ran[i].second = find(num, ran[i + 1].second);
		}
		else
			ran[i].second = min(*it, ran[i + 1].second);
		//cout<<ran[i].first<<" "<<ran[i].second<<endl;
	}
	//cout<<ran[0].first<<" "<<ran[0].second<<endl;
	for (int i = 1; i < T; i++) {
		num = t[i] - 'a';
		it = alp[num].begin();
		if (*it <= ran[i - 1].first) {
			ran[i].first = find1(num, ran[i - 1].first);
		}
		//cout<<ran[i].first<<" "<<ran[i].second<<endl;
	}
	for (int i = 0; i < T - 1; ++i)
		ans = max(ans, ran[i + 1].second - ran[i].first - 1);
	ans = max(ans, S - 1 - ran[T - 1].first);
	ans = max(ans, ran[0].second);
	printf("%d\n", ans);
	return 0;
}
