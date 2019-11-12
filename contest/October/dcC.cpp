    /* author Dc-HITMAN */
            /*#pragma warning(disable:4996)
                #pragma comment(linker, "/stack:200000000")*/
                //#pragma GCC optimize ("-ffloat-store")
            
                #include<iostream>
                #include<bits/stdc++.h>
                #include<stdio.h>
                using namespace std;
                    //#define TRACE
            
                    //#ifdef TRACE
                /*    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
                    template <typename Arg1>
                    void __f(const char* name, Arg1&& arg1){
                        cerr << name << " : " << arg1 << std::endl;
                    }
                    template <typename Arg1, typename... Args>
                    void __f(const char* names, Arg1&& arg1, Args&&... args){
                        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
                    }
                    //#else
                    //#define trace(...)
                //    #endif*/
            
                    #define rep(i, n)    for(int i = 0; i < (n); ++i)
                    #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
                    #define repD(i, a, n)  for(int i = a; i >= (n); --i)
                    #define trav(a, x) for(auto& a : x)
                    #define all(x) x.begin(), x.end()
                    #define sz(x) (int)(x).size()
                    #define fill(a)  memset(a, 0, sizeof (a))
                    #define fst first
                    #define snd second
                    #define mp make_pair
                    #define pb push_back
                    typedef long  double ld;
                    typedef long long int ll;
                    typedef pair<int, int> pii;
                    typedef vector<int> vi;
            
                
           struct UF {
                        vi e;
                        UF(int n) : e(n, -1) {}
                        bool same_set(int a, int b) { return find(a) == find(b); }
                        int size(int x) { return -e[find(x)]; }
                        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
                        void join(int a, int b) {
                            a = find(a), b = find(b);
                            if (a == b) return;
                            if (e[a] > e[b]) swap(a, b);
                            e[a] += e[b]; e[b] = a;
                        }
                };
                //int st[1000000][24];
     
    //ll p=1000000007;
    //int x=10002;
    /*ll power(long long int a, int b)
    {
        if(!b)
            return 1;
        long long int ans = power(a, b/2);
        ans = (ans*ans)%p;
        if(b%2)
            ans = (ans*a)%p;
        return ans;
    }*/
     
    int main() {
       cin.sync_with_stdio(0); cin.tie(0);
        cin.exceptions(cin.failbit);
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll a,b=0,c=0,d,e,f,ans=0,c1,b1;
        int i=0;
        ll dp[n+1][2];
        a=-1;b=-1;
        for(int i=0;i<=n;i++)rep(j,2)dp[i][j]=-1;
        for(int i=0;i<n;i++){
            dp[i][0]=a;
            dp[i][1]=b;
            if(s[i]=='A')a=i;
            else b=i;
        }
        b=0;c=0;
        while(i<n){
          //  cout<<i<<endl;
            //cout<<a<<" ";
           // cout<<a<<" ";
           a=i;
           if(s[i]=='A'){
               b++;
               c=0;
           }
           else {
               b=0;
               c++;
           }
            if(s[a]=='A'){
                d=b;
              //  cout<<d<<"d "<<i<<endl;
               // if(d<=1){i++;continue;}
               // d=((d*(d+1))/2-d);
                ans+=(d-1);
                //cout<<ans<<endl;
                c1=dp[i][1];
                if(c1!=-1){
                    
                    c1--;}
     
                if(d==1)c1=min(c1,dp[i][0]);
               // if(c1==-1){i++;continue;}
               // else{
                    ans+=(c1+1);
                //}
                //cout<<ans<<" "<<i<<endl;
            }
            else{
                d=c;
              //  if(d<=1){i++;continue;}
                //d=((d*(d+1))/2-d);
                ans+=(d-1);
                c1=dp[i][0];
                if(c1!=-1)c1--;
                if(d==1)c1=min(c1,dp[i][1]);
               // if(c1==-1){i++;continue;}
                //else{
                    ans+=(c1+1);
                //}
                //cout<<ans<<" "<<i<<endl;
            }
           // cout<<ans<<endl;
            i++;
        }
        cout<<ans<<endl;
        
    }    
