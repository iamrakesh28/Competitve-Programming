#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5, prime = 1e9 + 7;
int arr[N], dup[N];
long long fact[N], po[N];
multiset <int> s;

long long power(long long a, long long n) {
	long long r = 1;
	while (n) {
		if (n & 1)
			r = r * a % prime;
		a = a * a % prime;
		n = n >> 1;
	}
	return r;
}

int main() {

	int q;
	scanf("%d", &q);
	fact[0] = 1;
	po[0] = power(1, prime - 2);
	for (int i = 1; i <= (N >> 1); ++i) {
		fact[i] = fact[i - 1] * i % prime;
		po[i] = power(fact[i], prime - 2);
	}

	while (q--) {
		int n, pos = 1, cnt = 0, x, neg;
		long long sum = 0, ans;
		char ch;
		s.clear();
		scanf("%d", &n);
		ch = getchar_unlocked();
		for (int i = 0; i < (n << 1); ++i) {
			x = 0;
			neg = 0;
			while ((ch = getchar_unlocked()) != ' ' && ch != '\n') {
				if (ch == '-')
					neg = 1;
				else
					x = 10 * x + ch - '0';
			}
			if (neg)
				x = -x;
			//scanf("%d", arr + i);
			arr[i] = x;
			sum = sum + arr[i];
			s.insert(arr[i]);
		}
		if (sum % (n + 1)) {
			puts("0");
			continue;
		}
		sum = sum / (n + 1);
		//cout<<sum<<endl;
		for (int i = 0; i < (n << 1); ++i)
			if (arr[i] == sum)
				cnt++;
		if (cnt < 2) {
			puts("0");
			continue;
		}
		s.erase(s.find(sum));
		s.erase(s.find(sum));
		int nxt, ele;
		cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			auto it = s.begin();
			ele = *it;
			s.erase(it);
			it = s.find(sum - ele);
			if (it == s.end()) {
				pos = 0;
				break;
			}
			nxt = *it;
			s.erase(it);
			dup[i] = min(ele, nxt);
			if (ele != nxt)
				cnt++;
		}
		if (pos == 0) {
			puts("0");
			continue;
		}
		sort(dup, dup + n - 1);
		ans = power(2, cnt);
		ans = ans * fact[n - 1] % prime;
		
		nxt = 1;
		for (int i = 1; i < n - 1; ++i) {
			if (dup[i] != dup[i - 1]) {
				if (nxt != 1)
					ans = ans * po[nxt] % prime;
				nxt = 1;
			}
			else
				nxt++;
		}
		if (nxt != 1)
			ans = ans * po[nxt] % prime;
		
		printf("%lld\n", ans);
	}
	return 0;
}


