#include<stdio.h>
void print(int *a,int n)
{
	for(int i=0;i<n;++i)
	{
		printf("%d",a[i]);
	}
}
void rec(int l,int *a,int n)
{
	for(int i=0;i<10;++i)
	{
		a[l-1]=i;
		if(l!=n)
		rec(l+1,a,n);
		printf(" \n");
		print(a,n);
	}
}

int main()
{
	int l,min,max;
	int a[10];
	printf(" Enter minimum length : ");
	scanf("%d",&min);
	printf(" Enter maximum length : ");
	scanf("%d",&max);
	for(int i=min;i<=max;++i)
	rec(1,a,i);
	return 0;
}
