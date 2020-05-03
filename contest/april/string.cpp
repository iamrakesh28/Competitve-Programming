#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
char S[N], V1[N], V2[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", S);
    int n = strlen(S);
    for (int i = 1; i < n; ++i)
      V1[i - 1] = S[i];
    V1[n - 1] = S[0];
    V1[n] = '\0';
    for (int i = 0; i < n - 1; ++i)
      V2[i + 1] = S[i];
    V2[0] = S[n - 1];
    V2[n] = '\0';
    if (strcmp(V1, V2) == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
