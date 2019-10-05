#include <bits/stdc++.h>

using namespace std;
int best;
int ind,cnt;
void backtrack(int n,int num,vector <int> &track,int indexn,int value,int mask,int count)
{
	if(value > n)
	return;
	if(indexn == num)
	{
		if(value > best)
		{
			best = value;
			ind = mask;
			cnt = count;
		}
		else if(value == best && count > cnt)
		{
			ind = mask;
			cnt = count;
		}
		return;
	}
	backtrack(n,num,track,indexn+1,value,mask,count);
	backtrack(n,num,track,indexn+1,value+track[indexn],mask | 1 << indexn,count+1);
}
int main()
{
	int n,num;
	while(scanf("%d%d",&n,&num) != EOF)
	{
		best = 0;
		cnt = 0;
		vector <int> track(num);
		for(int i=0;i<num;++i)
		cin>>track[i];
		backtrack(n,num,track,0,0,0,0);
		for(int i=0;i<num;++i)
		{
			if((ind >> i)%2)
			printf("%d ",track[i]);
		}
		printf("sum:%d\n",best);
	}
	return 0;
}
