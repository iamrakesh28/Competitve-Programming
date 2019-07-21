#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void maximum(int n,int m,int i,int j,int *maxa,int *max,int *maxb)
{
	int first,last,a,b,psmax;
	first=(n-i)*3-(m-j)*3+i*2-j*2;
	last=(n-i)*2-(m-j)*2+i*3-j*3;
	if(first>last)
	{
		psmax=first;
		a=(n-i)*3+i*2;
		b=(m-j)*3+j*2;
		printf("%d %d %d\n",a,b,psmax);
	}
	else if(first==last)
	{
		int c,d;
		c=(n-i)*3+i*2;
		d=(n-i)*2+i*3;
		psmax=first;
		if(c>d)
		{
			a=c;
			b=(m-j)*3+j*2;
		}
		else
		{
			a=d;
			b=(m-j)*2+j*3;
		}
	}
	else
	{
		psmax=last;
		a=(n-i)*2+i*3;
		b=(m-j)*2+j*3;
	}
	if(psmax>*max)
	{
		*max=psmax;
		*maxa=a;
		*maxb=b;
	}
	else if(psmax==*max)
	{
		if(*maxa<a)
		{
			*maxa=a;
			*maxb=b;
		}
	}
}

int main()
{
	int n,m,max=INT_MIN,maxa=INT_MIN,maxb,val,i,j;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
	}
	scanf("%d",&m);
	int *b=(int *)malloc(sizeof(int)*m);
	for(int i=0;i<m;++i)
	{
		scanf("%d",b+i);
	}
	for(i=0,j=0;i+j<=m+n-2;)
	{
		//printf("he");
		maximum(n,m,i,j,&maxa,&max,&maxb);
		if(a[i]<b[j])
		{	if(i<n-1)	
			++i;
		}
		else
		{	if(j<m-1)
			++j;
		}
	}
	maximum(n,m,n,m,&maxa,&max,&maxb);
	printf("%d:%d\n",maxa,maxb);
	return 0;
}
