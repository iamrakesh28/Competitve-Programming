#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city{
	char ci[100];
	int i;
}; 
int find(struct city *st, char *pt,int n)
{
	for(int i=0;i<n;++i)
	{
		if(strcmp(pt,st[i].ci)==0)
		{
			return st[i].i;
		}
	}
	return 0;
}
	
int recursion(int **arr, int start, int end, int n,int org,int val)
{
	if(val&&(start==org))
	return 0;
	for(int i=0;i<n;++i)
	{
		if(arr[start][i])
		{
			if(i==end)
			return 1;
			if(recursion(arr,i,end,n,org,val+1))
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int **arr=(int **)malloc(sizeof(int *)*n);
	struct city *st=(struct city *)malloc(sizeof(struct city)*n);
	for(int i=0;i<n;++i)
	{
		arr[i]=(int *)calloc(n,sizeof(int));
		scanf("%s",st[i].ci);
		st[i].i=i;
		//printf("\n%s",st[i].ci);
	}
	char ch[100],c[100],a[100],b[100],*ptr,test=getchar();
	fgets(ch,100,stdin);
	ptr=ch;
	for(int mn;*ptr!='\0';)
	{
		sscanf(ptr,"%[^,]s",c);
		sscanf(c,"%s%s",a,b);
		mn=strlen(a)+strlen(b)+1;
		ptr+=mn+1;
		int r,k;
		r=find(st,a,n);
		k=find(st,b,n);
		arr[r][k]=1;
		//arr[d][c]=1;
	}
	scanf("%s%s",a,b);
	int r,k;
	r=find(st,a,n);
	k=find(st,b,n);
	if(recursion(arr,r,k,n,r,0))
	printf("YES");
	else
	printf("NO");
	return 0;
}
