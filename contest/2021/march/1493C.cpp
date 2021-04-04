#include <iostream>

using namespace std;

const int N = 1e5 + 5;

char s[N], ans[N];
int freq[26], rem[26];

bool solve(int i, int n, int k) {

  int sum = 0;
  for (int j = 0; j < 26; ++j) {
    if (freq[j] > 0)
      rem[j] = k - (freq[j] % k);
    else
      rem[j] = 0;

    if (rem[j] == k)
      rem[j] = 0;

    sum += rem[j];
  }

  if (i >= n) {
    if (sum > 0)
      return false;
    return true;
  }
  int rem_cnt = n - i;

  if (sum > rem_cnt) {
    return false;
  }
  //if (rem_cnt % k) {
  //  return false;
  //}

  rem_cnt = rem_cnt - sum;
  if (rem_cnt % k) {
    return false;
  }

  int j = i;
  while (rem_cnt > 0) {
    ans[j++] = 'a';
    rem_cnt--;
  }

  for (; j < n; ++j) {
    int found;
    for (int r = 0; r < 26; ++r) {
      if (rem[r] > 0) {
        rem[r]--;
        found = r;
        break;
      }
    }
    ans[j] = found + 'a';
  }
  
  return true;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d%s", &n, &k, s);

    if (n % k) {
      puts("-1");
      continue;
    }

    for (int i = 0; i < 26; ++i) {
      freq[i] = 0;
      rem[i] = 0;
    }
    
    for (int i = 0; i < n; ++i) {
      freq[s[i] - 'a']++;
    }

    bool poss = true;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] % k) {
        poss = false;
        break;
      }
    }

    if (poss) {
      puts(s);
      continue;
    }
    
    for (int i = n - 1; i >= 0; i--) {
      for (int j = s[i] - 'a' + 1; j < 26; ++j) {
        freq[s[i] - 'a']--;
        freq[j]++;
        
        if (solve(i + 1, n, k)) {
          poss = true;
          ans[i] = j + 'a';
          for (int r = 0; r < i; ++ r)
            ans[r] = s[r];

          break;
        }

        freq[s[i] - 'a']++;
        freq[j]--;
      }
      if (poss)
        break;

      freq[s[i] - 'a']--;
    }

    ans[n] = '\0';
    puts(ans);
  }
  
  return 0;
}
