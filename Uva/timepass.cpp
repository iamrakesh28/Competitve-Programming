#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int v;
	for(int i=0;i<n;++i)
	scanf("%d",&v);
	for(int i=1;i<n;++i)
	printf("%d %d\n",i,i+1);
	return 0;
}
