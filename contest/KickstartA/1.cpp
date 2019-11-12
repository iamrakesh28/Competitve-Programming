#include <bits/stdc++.h>

#define N 100005
#define INF 1000000000
using namespace std;

int arr[N],pref[N];
int sum(int i)
{
	if(i < 0)
		return 0;
	return pref[i]; 
}
int solve(int n,int p)
{
	pref[0] = arr[0];
	int ans = INF;
	for(int i=1;i<n;++i)
		pref[i] = pref[i-1] + arr[i];
	for(int i=n-1;i>=0 && i+1 >= p;--i) {
		int val = arr[i]*p - (sum(i) - sum(i-p));
		ans = min(val,ans);
	}
	return ans;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i) {
		int n,p;
		scanf("%d%d",&n,&p);
		for(int j=0;j<n;++j)
			scanf("%d",arr+j);
		sort(arr,arr+n);
		printf("Case #%d: %d\n",i+1,solve(n,p));
	}
}
