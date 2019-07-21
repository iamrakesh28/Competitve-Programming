#include<stdio.h>
void print(char *a,int n)
{
	printf("Pass#");
	for(int i=0;i<n;++i)
	{
		printf("%c",a[i]);
	}
}
void rec(int l,char *a,int n)
{
	for(int i=48;i<=57;++i)
	{
		a[l-1]=i;
		if(l!=n)
		rec(l+1,a,n);
		printf(" \n");
		print(a,n);
		//printf("%s",a);
	}
}

int main()
{
	int l,min,max;
	char a[10];
	printf(" Enter minimum length : ");
	scanf("%d",&min);
	printf(" Enter maximum length : ");
	scanf("%d",&max);
	for(int i=min;i<=max;++i)
	rec(1,a,i);
	return 0;
}
