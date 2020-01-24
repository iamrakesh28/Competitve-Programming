    #include<iostream>
    #include<cstring>
    #include<cstdio>
    #include<map>
    using namespace std;
    #define ll long long
    const int N = 3e5 + 10;
    int a[N], n, b[N];
    map<int, ll> dp[N];
    int main(){
    	int T; scanf("%d", &T);
    	while(T--){
    		scanf("%d", &n);
    		for(int i = 1; i <= n; i++) dp[i].clear();
    		for(int i = 1; i <= n; i++)
    		  scanf("%d%d", &a[i], &b[i]);
    		for(int i = 0; i <= 10; i++)
    		  dp[1][a[1] + i] = 1LL * i * b[1];
    		for(int i = 2; i <= n; i++)
    		  for(int j = 0; j <= 10; j++){
    			  dp[i][a[i] + j] = 1e18;
    			  for(int k = 0; k <= 10; k++)
    				if(a[i - 1] + k != a[i] + j)
    				  dp[i][a[i] + j] = min(dp[i][a[i] + j], dp[i - 1][a[i - 1] + k] + 1LL * j * b[i]);
    		  }
    		ll ans = 1e18;
    		for(int i = 0; i <= 10; i++)
    		  ans = min(ans, dp[n][a[n] + i]);
    		printf("%I64d\n", ans);
    	}
    	return 0;
    }


