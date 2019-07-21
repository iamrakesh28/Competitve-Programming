#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector <pair <int,int>> A(n),B(m);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&A[i].first);
		A[i].second = i;
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d",&B[i].first);
		B[i].second = i;
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i=0;i<m;++i)
	printf("%d %d\n",A[0].second,B[i].second);
	for(int i=1;i<n;++i)
	printf("%d %d\n",A[i].second,B[m-1].second);
	return 0;
}
