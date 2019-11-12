#include <bits/stdc++.h>

using namespace std;

char N[105],B[105];
int divide(void)
{
	int len = strlen(N),i;
	for(i=0;i<len;++i) {
		if(N[i] == '4') {
			B[i] = '1';
			N[i] = '3';
		}
		else
			B[i] = '0';
	}
	B[i] = '\0';
	int ind = 0;
	while(B[ind] == '0')
		ind++;
	return ind; 
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i) {
		scanf("%s",N);
		int ind = divide();
		printf("Case #%d: %s %s\n",i+1,N,B+ind);
	}
	return 0;
}
