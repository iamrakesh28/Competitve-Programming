#include <iostream>

using namespace std;

const int prime = 1e9 + 7, N = 1e6;
int A[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", A + i);
  long long ans = 0, temp, size = 1, cor = 0, diag = 0, prev;
  for (int i = 0; i < n; ++i) {
    ans = ans << 2;
    temp = cor + size * 3 * A[i] + size * cor;
    ans = ans + 4 * temp;
    //cout<<ans<<endl;
    temp = cor + size * 2 * A[i] + size * cor;
    ans = ans + 2 * temp;
    //cout<<ans<<endl;
    temp = cor + size * A[i];
    ans = ans + 4 * temp + A[i];
    temp = cor + size * 2 * A[i];
    ans = ans + 4 * temp;
    //cout<<temp<<" "<<ans<<endl;
    prev = cor;
    temp = size * (3 * A[i] + diag) + cor;
    cor = cor + 2 * temp;
    //cout<<cor<<endl;
    temp = size * (2 * A[i] + diag) + prev;
    cor = cor + temp + 3 * A[i] + 2 * diag;
    cout<<cor<<endl;
    size = 4 * size + 2;
    diag = 2 * diag + 3 * A[i];
  }
  printf("%lld\n", ans);
  return 0;
}
