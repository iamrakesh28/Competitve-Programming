#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;
char input_s[N], ans[N];

struct State {
    int steps, child;
    char digit;
};

vector <State> pointers;

class SuffixArray {
    int n;
    vector <int> p, c;
    string str;

public:
    int index;
    SuffixArray(char s[], int n) : n(n), str(s) {
        p.resize(n);
        c.resize(n);

        vector <int> cnt(max(n, 2), 0);
        for (int i = 0; i < n; ++i)
            cnt[s[i] - '0'] ++;
        for (int i = 1; i < 2; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i)
            p[--cnt[s[i] - '0']] = i;

        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i - 1]])
                classes++;
            c[p[i]] = classes - 1;
        }

        vector <int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);

            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }

            for (int i = 0; i < n; ++i)
                c[i] = cn[i];
        }

        /*
          for (int i = 0; i < n; ++i) {
          for (int j = p[i]; j < n; ++j)
          cout << s[j];
          cout << endl;
          }
        */
    }

    void remove_suffix(int k) {

        index = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] + k - 1 >= n)
                continue;
            p[index ++] = p[i];
        }

        /*
          for (int i = 0; i < index; ++i) {
          for (int j = p[i]; j < n; ++j)
          cout << str[j];
          cout << endl;
          }
        */
        
        
        return;
    }

    int upper_bound_zero(int start, int end, int depth) {

        int bound = -1, mid;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (str[p[mid] + depth] == '0') {
                bound = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return bound;
    }

    ~SuffixArray() {}
  
};

int dfs_poss(SuffixArray &arr, int l, int r, int depth) {

    int bound = arr.upper_bound_zero(l, r, depth);
    if (bound == -1 || bound == r)
        return 1;

    int dp_left = dfs_poss(arr, l, bound, depth + 1);
    int dp_right = dfs_poss(arr, bound + 1, r, depth + 1);

    return min(dp_left, dp_right) + 1;
}

int dfs_sol(SuffixArray &arr, int l, int r, int depth) {

    int bound = arr.upper_bound_zero(l, r, depth);

    if (bound == -1 || bound == r) {

        State child = {1, -1, '0'};
        if (bound == -1)
            child.digit = '1';
        pointers.push_back(child);

        return pointers.size() - 1;
    }

    int index_l = dfs_sol(arr, l, bound, depth + 1);
    int index_r = dfs_sol(arr, bound + 1, r, depth + 1);

    if (pointers[index_l].steps < pointers[index_r].steps) {

        State child = {pointers[index_l].steps + 1, index_l, '1'};
        pointers.push_back(child);
    }
    else {
        
        State child = {pointers[index_r].steps + 1, index_r, '0'};
        pointers.push_back(child);
    }
    
    return pointers.size() - 1;
}

void find_lexo(int index, int i, int k) {

    while (index != -1) {
        ans[i ++] = pointers[index].digit;
        index = pointers[index].child;
    }

    while (i < k)
        ans[i ++] = '0';
    
    ans[i] = '\0';

    return;
}

int main() {

    int q;
    scanf("%d", &q);

    while (q--) {
        int n, k;
        scanf("%d%d%s", &n, &k, input_s);

        reverse(input_s, input_s + n);
        SuffixArray suff_rev(input_s, n);
        suff_rev.remove_suffix(k);

        int min_k = dfs_poss(suff_rev, 0, suff_rev.index - 1, 0);

        if (min_k > k) {
            puts("NO");
            continue;
        }

        reverse(input_s, input_s + n);
        int len = k - min_k;

        for (int i = len; i < n; ++i)
            input_s[i - len] = input_s[i];
        input_s[n - len] = '\0';

        SuffixArray suff_org(input_s, n - len);
        suff_org.remove_suffix(min_k);
        
        pointers.clear();
        int index = dfs_sol(suff_org, 0, suff_org.index - 1, 0);
        find_lexo(index, len, k);

        for (int i = 0; i < len; ++i)
            ans[i] = '0';

        puts("YES");
        puts(ans);
    }
  
    return 0;
}
