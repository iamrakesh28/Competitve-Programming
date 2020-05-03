#include<iostream>
#include<vector>

using namespace std;

const int N = static_cast<int>(1e6);
int n, d, a[N], dp[N][2];
// dp[i][0]: max length of subsequence from a[0..i] ending at a[i] and a[prev] >= a[i] + k
// dp[i][1]: max length of subsequence from a[0..i] ending at a[i] and a[prev] <= a[i] - k

vector<int> t0, t1;
// t0: segment tree for max over dp[.][0]
// t1: segment tree for max over dp[.][1]

// max value occurring in input
int max_val;

void readInput() {
    scanf("%d %d", &n, &d);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        max_val = max(max_val, a[i]);
    }
}

// Initialize segment tree
void segTreeInit() {
    t0.clear();
    t0.assign(4 * (max_val + 1), 0);
    t1.clear();
    t1.assign(4 * (max_val + 1), 0);
}

inline int left(int i) {return i << 1;}
inline int right(int i){return (i << 1) + 1;}

// range maximum query
int rmq(vector<int> &t, int p, int L, int R, int l, int r) {
    
    if(l == L && R == r) {
        return t[p];
    }

    int mid = (L + R) >> 1;
    
    if(r <= mid)
        return rmq(t, left(p), L, mid, l, r);
    else if(l >= mid + 1)
        return rmq(t, right(p), mid + 1, R, l, r);
    else
        return max(
            rmq(t, left(p), L, mid, l, mid),
            rmq(t, right(p), mid + 1, R, mid + 1, r)
        );
}

void update(vector<int> &t, int p, int L, int R, int idx, int val) {

    if(L == R) {
        t[p] = val;
        return;
    }

    int mid = (L + R) >> 1;

    if(idx <= mid)
        update(t, left(p), L, mid, idx, val);
    else
        update(t, right(p), mid + 1, R, idx, val);

    t[p] = max(t[left(p)], t[right(p)]);
}

// compute dp array
void computeDP() {

    for(int i = 0;i < n;i++) {

        if(a[i] - d < 0)
            dp[i][0] = 0;
        else {
            dp[i][0] = rmq(t1, 1, 0, max_val, 0, a[i] - d) + 1;

            if(rmq(t0, 1, 0, max_val, a[i], a[i]) < dp[i][0])
                update(t0, 1, 0, max_val, a[i], dp[i][0]);
        }

        if(a[i] + d > max_val)
            dp[i][1] = 0;
        else {
            dp[i][1] = rmq(t0, 1, 0, max_val, a[i] + d, max_val) + 1;

            if(rmq(t1, 1, 0, max_val, a[i], a[i]) < dp[i][1])
                update(t1, 1, 0, max_val, a[i], dp[i][1]);
        }
    }
}

void getAns() {
    int ans = 0;

    for(int i = 0;i < n;i++)
        ans = max(ans, max(dp[i][0], dp[i][1]));

    printf("%d\n", ans);
}

int main() {

    readInput();
    segTreeInit();
    computeDP();
    getAns();

    return 0;
}