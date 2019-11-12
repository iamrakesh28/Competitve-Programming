#include <bits/stdc++.h>

#define N 105
using namespace std;

long int prod[N];
pair <long int,int> prime[N]; 
char ans[N];

long int gcd(long int a, long int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i = 0;i < q;++i) {
		int n,l,ind;
		scanf("%d%d",&n,&l);
		for(int j = 0 ;j < l; ++j) {
			scanf("%ld",prod+j);
			if(j && prod[j] != prod[j-1])
				ind = j;
			prime[j].second = j;
		}
		int j = ind+1;
		long int p = gcd(prod[ind],prod[ind-1]);
		prime[ind].first = p;
		prime[l].second = l;
		while(j <= l) {
			prime[j].first = prod[j-1]/p;
			p = prime[j].first;
			j++;	
		}
		j = ind-1;
		p = gcd(prod[ind],prod[ind-1]);
		//cout<<p<<" "<<ind<<endl;
		while(j >= 0) {
			prime[j].first = prod[j]/p;
			p = prime[j].first;
			j--;	
		}
		sort(prime,prime+l+1);
		char ch = 'A';
		ans[prime[0].second] = ch;
		//cout<<prime[0].first<<" ";
		for(int j = 1 ;j <= l; ++j) {
			if(prime[j].first != prime[j-1].first)
				ans[prime[j].second] = ++ch;
			else
				ans[prime[j].second] = ch;
			//cout<<prime[j].first<<" ";
		}
		ans[l+1] = '\0';
		printf("Case #%d: %s\n",i+1,ans);
	}
	return 0;
}

