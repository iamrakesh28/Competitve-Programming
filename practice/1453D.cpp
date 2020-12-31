#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int main() {

  int t;
  scanf("%d", &t);

  vector <int> stages;
  
  while (t--) {
    LL k;
    scanf("%lld", &k);

    stages.clear();
    
    if (k & 1) {
      puts("-1");
      continue;
    }

    stages.push_back(1);
    
    while (k > 0) {

      LL num = 2;
      int cnt = 1;
      
      while (2 * (num + 1) <= k) {
        num = 2 * (num + 1);
        cnt++;
      }

      k -= num;
      for (int i = 0; i < cnt - 1; ++i)
        stages.push_back(0);

      if (k > 0)
        stages.push_back(1);
    }

    printf("%d\n", stages.size());
    for (int stage : stages)
      printf("%d ", stage);
    puts("");
    
  }
  
  return 0;
}
