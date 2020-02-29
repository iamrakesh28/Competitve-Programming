#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <set>
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <map>
 
#define DEB(X) printf("%s = %d\t\tline %d\n", #X, X, __LINE__)
using namespace std;
 
int n, m;
vector<pair<int, int>> h;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        h.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> h[i].first >> h[i].second;
        }
 
        sort(h.begin(), h.end());
 
        vector<int> sufmax(m);
        sufmax[m - 1] = h[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            sufmax[i] = max(h[i].second, sufmax[i + 1]);
        }
 
        int i = 0, j = 0;
        int curmax = -1;
        int ans = 0;
        bool ok = true;
        while (i < n) {
            curmax = a[i];
 
            while (j < n) {
                curmax = max(curmax, a[j]);
                int kk = lower_bound(h.begin(), h.end(), curmax, [curmax](const pair<int, int>& p, int x){
                    return p.first < curmax;
                }) - h.begin();
 
                if (sufmax[kk] < j + 1 - i || kk == m) {
                    break;
                } else {
                    ++j;
                }
            }
 
            ++ans;
            if (i == j) {
                ok = false;
                break;
            }
            i = j;
        }
 
        cout << (ok ? ans : -1) << '\n';
    }
    return 0;
}
 
 
