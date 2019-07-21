#include <stdio.h>

#define li long int
#define size 40

int str(char *string,li *damage,int *pos)
{
	li strength=1;
	int length=0,count=0;
	while(*string!='\0')
	{
		if(*string == 'S')
		{
			*damage += strength;
			pos[length]++;
		}
		else
		{
			strength *=2;
		}
		length++;
		string++;
	}
	return length;
}
void swap(char *a, char *b)
{
	char temp=*a;
	*a = *b;
	*b = temp;
}
li min(int *pos,int n,li d,char *string,li *prev)
{
	li minimum=0,damage = *prev,strength;
	for(int j=0;j<n;++j)
	{
		strength =1;
		for(int i=0;i<n-1;++i)
		{
			if(damage <= d)
			return minimum;
			if(string[i]=='C')
			strength*=2;
			if(string[i]=='C'&& string[i+1]=='S')
			{
				swap(string+i,string+i+1);
				minimum++;
				strength/=2;
				damage = damage - strength;
				//printf("%s\n",string);
			}
		}
	}
	if(damage <= d)
	return minimum;
	return -1;
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		li d,damage=0,minimum;
		int length,pos[size]={0};
		char string[size];
		scanf("%ld%s",&d,string);
		length = str(string,&damage,pos);
		for(int j=length-1;j>0;--j)
		{
			pos[j-1]+=pos[j];
		}
		minimum=min(pos,length,d,string,&damage);
		printf("Case #%d: ",i);
		if(minimum == -1)
		printf("IMPOSSIBLE\n");
		else
		printf("%ld\n",minimum);
	}
	return 0;
}
