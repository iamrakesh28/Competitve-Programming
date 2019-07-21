#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int n,p,m,rem,triplet=0;
		scanf("%ld%ld",&n,&p);
		if(n == 1 || n == 2)
		{
			triplet = p*p*p;
			printf("%ld\n",triplet);
			continue;
		}
		m = n/2 + 1;
		rem = n%m;
		//cout<<rem<<"\t";
		//fixing i
		triplet += (p-rem)*(p-rem);
		//fixing j
		triplet += (p-n)*(p-rem);
		//fixing k
		triplet += (p-n)*(p-n);
		printf("%ld\n",triplet);  
	}
	return 0;
}
