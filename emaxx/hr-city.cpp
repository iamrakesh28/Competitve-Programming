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
    ans = ans % prime;
    temp = 2 * (size * cor % prime) + 3 * (size * size % prime) * A[i];
    temp = temp % prime;
    ans = (ans + 4 * temp) % prime;
    //cout<<ans<<endl;
    temp = 2 * (size * cor % prime) + 2 * (size * size % prime) * A[i];
    temp = temp % prime;
    ans = (ans + 2 * temp) % prime;
    //cout<<ans<<endl;
    temp = (cor + size * A[i]) % prime;
    ans = (ans + 4 * temp + A[i]) % prime;
    temp = (cor + size * 2 * A[i]) % prime;
    ans = (ans + 4 * temp) % prime;
    //cout<<temp<<" "<<ans<<endl;
    prev = cor;
    temp = 3 * size * A[i] % prime + diag * size % prime + cor;
    temp = temp % prime;
    cor = cor + 2 * temp;
    cor = cor % prime;
    //cout<<cor<<endl;
    temp = 2 * size * A[i] % prime + size * diag % prime + prev;
    temp = temp % prime;
    cor = cor + temp + 3 * A[i] + 2 * diag;
    cor = cor % prime;
    //cout<<cor<<endl;
    size = (4 * size + 2) % prime;
    diag = (2 * diag + 3 * A[i]) % prime;
  }
  printf("%lld\n", ans);
  return 0;
}
