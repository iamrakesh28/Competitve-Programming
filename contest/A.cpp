#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int main()
{
	int n,l=0,r=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		scanf("%d",arr+i);
		if(arr[i] == 0)
			l++;
		else
			r++;
	}
	int k,u=0,d=0;
	for(int i=0;i<n;++i) {
		if(arr[i] == 0)
			u++;
		else
			d++;
		if(u == l || d == r)
			{ k = i+1; break;}
	}
	printf("%d\n",k);
	return 0;
}
