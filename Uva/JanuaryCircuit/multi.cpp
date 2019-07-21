#include <bits/stdc++.h>

#define PRIME 1000000007
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long int *A = new long int[n];
	long int *B = new long int[n];
	for(int i=0;i<n;++i)
	scanf("%ld",A+i);
	for(int i=0;i<n;++i)
	scanf("%ld",B+i);
	sort(A,A+n);
	sort(B,B+n);
	long int ans = 0;
	for(int i=0;i<n;++i)
	ans = (ans + abs(A[i]-B[i])%PRIME)%PRIME;
	printf("%ld\n",ans);
	delete [] A,B;
	return 0;
}
