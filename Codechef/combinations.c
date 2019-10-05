#include<stdio.h>
#include<string.h>
void print(char *p, int n)
{
	for(int i=0;i<n;++i)
	{
		printf(" %c",p[i]);
	}
	printf("\n");
}
void comb(int n,char *s,char *p,int len,int c,int j,int i)
{	
	for(i;i<len-n+1;++i)
	{	
		p[j]=s[i];
		if(c!=n)
		{ 
		comb(n,s,p,len+1,c+1,j+1,i+1);		
		}
		else
		print(p,n);
                
	}
}
int main()
{	
	char s[10],p[10];
	int n;
	printf("Enter a string : "); 
	scanf("%s",s);
	printf("Enter number of elements in a pair : ");
	scanf("%d",&n);
	int len=strlen(s);
	comb(n,s,p,len,1,0,0);
	return 0;
}
