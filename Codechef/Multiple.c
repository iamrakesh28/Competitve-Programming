#include <stdio.h>

int sumcalc(int sum10, int sum,int k,int *arr)
{
	
	int i,same=sum10=(sum10+sum10%10)%10;
	sum10=(sum10+sum10%10)%10;
	sum+=sum10;
	//int arr[1000];
	for(i=0;sum10!=same;++i)
	{
		sum10=(sum10+sum10%10)%10;
		sum+=sum10;
		arr[i+3]=sum;
	}
	int mod=(k%(i+3));
	if(mod!=0)
	{
		if((((k%3)*(sum%3))%3+arr[mod-1]%3)%3==0)
		return 1;
		else
		return 0;
	}
	return 1;
	/*if(sum3==0)
	return 1;
	else
	return 0;*/
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int k,d0,d1,sum10;
		scanf("%d%d%d",&k,&d0,&d1);
		int arr[1000];
		sum10=(d0+d1)%10;
		arr[0]=d0,arr[1]=d1,arr[2]=sum10;
		if(sumcalc(sum10,sum10+d0+d1,k,arr))
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
