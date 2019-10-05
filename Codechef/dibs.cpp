#include <bits/stdc++.h>

#define loop(x) for(int i=0;i<x;++i)
#define PRIME 1000000007

using namespace std;

unsigned long int fib(int n,unsigned long int a,unsigned long int b)
{
	unsigned long int cur=b,prev=a,temp;
	for(int i=2;i<n;++i)
	{
		temp = cur;
		cur = (cur+prev)%PRIME;
		prev = temp;//(cur-prev)%PRIME;
		//printf("%ld\n",cur);
	}
	return cur;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int m,n;
		unsigned long int result,fir,sec,A_sum=0,B_sum=0;
		scanf("%d%d",&m,&n);
		unsigned long int *A = new unsigned long int[m];
		unsigned long int *B = new unsigned long int[m];
		loop(m)
		{
			scanf("%lu",A+i);
			A_sum= (A_sum+A[i])%PRIME;
		}
		loop(m)
		{
			scanf("%lu",B+i);
			B_sum= (B_sum+B[i])%PRIME;
		}
		fir = fib(n,1,0);
		sec = fib(n,0,1);
		result = (m*(((fir*A_sum)%PRIME+(sec*B_sum)%PRIME))%PRIME)%PRIME;
		printf("%lu\n",result);
	}
	return 0;
}
