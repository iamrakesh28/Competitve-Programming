#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
/******************************************
* AUTHOR : PANDRAVISAM SHIVA SANTHOSH *
* Handle : santhosh_80 *
* INSTITUTION : IIT Palakkad *
******************************************/
#define ll long long int 
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long >
#define umap unordered_map
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define inf LLONG_MAX
#define neg_inf LLONG_MIN
#define next_line cout << "\n"
#define what_is(x) cerr << #x << " is " << x << "\n";
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repj(j,a,b) for(int j = a; j < b; j++)

inline void read0(auto &v, int n) {
	for(int i = 0; i < n; i++){cin >> v[i];}
}
inline void read1(auto &v, int n) {
	for(int i = 1; i <= n; i++){cin >> v[i];}
}
inline void out0(auto &v, int n) {
	for(int i = 0; i < n; i++){cout << v[i] << " ";}
}
inline void out1(auto &v, int n){
	for(int i = 1; i <= n; i++){cout << v[i] << " ";}
}
inline void auto_print(auto &v){
	for(auto x: v)cout << x << " ";
}

const ll mod = 1000000007;
const ll N = 1e6;

bool is_possible(int mid, vector<ll>&tokens){

	if(mid == tokens.size()-1)return true;

	ll curr_val = 0;

	for(int i = 0; i <= mid; i++){
		curr_val += tokens[i];
	}
	for(int i = mid+1; i < tokens.size(); i++){
		if(curr_val >= tokens[i]){
			curr_val += tokens[i];
		}
		else{
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> v(n);
		read0(v, n);
		vector<ll> tokens = v;
		sort(all(tokens));
		if(n == 1){
			cout << "1\n1\n";
			continue;
		}

		ll ans1 = tokens[n-1];
		vector<ll> val;

		int low = 0, high = n-1;
		while(low <= high){
			int mid = (low+high)/2;
			if(is_possible(mid, tokens)){
				ans1 = tokens[mid];
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}

		for(int i = 0; i < v.size(); i++){
			if(ans1 <= v[i]){
				val.pb(i+1);
			}
		}

		sort(all(val));
		cout << val.size() << "\n";
		for(auto x : val){
			cout << x << " ";
		}
		cout << "\n";
	}
 	return 0;
}
