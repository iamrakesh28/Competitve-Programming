int minStringCoeff(string s, int p) {
    vector <int> freq, pref;
    int i, cnt = 1, sum = 0, ans = 0, j = 0;
    for (i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) {
            if (j) {
                freq.push_back(cnt);
                sum += cnt;
            }
            j = 1;
            cnt = 1;
        }
        else
            cnt++;
    }
    if (freq.size() <= 0)
        return 0;
    pref.resize(freq.size());
    pref[0] = 0;
    for (int i = 0; i < freq.size(); ++i) {
        if (i)
            pref[i] = pref[i - 1];
        pref[i] += freq[i];
    }
    i = 0, j = freq.size() - 1;
    
    ans = sum - ans;
    return ans;
}
