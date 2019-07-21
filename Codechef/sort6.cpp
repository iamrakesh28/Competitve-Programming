    #include <cstdio>
    #include <cmath>
    #include <iostream>
    #include <set>
    #include <algorithm>
    #include <vector>
    #include <map>
    #include <cassert>
    #include <string>
    #include <cstring>
    #include <queue>
     
    using namespace std;
     
    #define rep(i,a,b) for(int i = a; i < b; i++)
    #define S(x) scanf("%d",&x)
    #define S2(x,y) scanf("%d%d",&x,&y)
    #define P(x) printf("%d\n",x)
    #define all(v) v.begin(),v.end()
    #define FF first
    #define SS second
    #define pb push_back
    #define mp make_pair
     
    typedef long long int LL;
    typedef pair<int, int > pii;
    typedef vector<int > vi;
     
    vi v;
     
    int main() {
      char ch;
      int x = 0;
      while((ch = getchar()) != '\n') {
        if(ch == ' ') {
          v.pb(x);
          x = 0;
        } else {
          x = x * 10 + (ch - '0');
        }
      }
      v.pb(x);
      sort(all(v));
      swap(v[v.size() / 2], v[v.size() / 2 - 1]);
      rep(i,0,v.size()) printf("%d ",v[i]); printf("\n");
      return 0;
    }
     