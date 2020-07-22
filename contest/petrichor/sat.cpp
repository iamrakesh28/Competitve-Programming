#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;
const int maxn = 100010;


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s.substr (i, 9) == "shivahmed") {
            cnt++;
            i += 8;
        } else if (s.substr (i, 5) == "shiva") {
            cnt++;
            i += 4;
        } else if (s.substr (i, 5) == "ahmed") {
            cnt++;
            i += 4;
        } else if (s.substr (i, 6) == "rakesh") {
            cnt++;
            i += 4;
        }
    }

    cout << cnt << "\n";


}
