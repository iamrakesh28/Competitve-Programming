#include <stdio.h>

#define li long int
#define size 40

int str(char *string,li *damage,li *power)
{
	li strength=1;
	int length=0,count=0;
	while(*string!='\0')
	{
		if(*string == 'S')
		{
			*damage += strength;
		}
		else
		{
			strength *=2;
		}
		length++;
		string++;
	}
	*power = strength;
	return length;
}
void swap(char *a, char *b)
{
	char temp=*a;
	*a = *b;
	*b = temp;
}
li min(int n,li d,char *string,li *prev,li *power)
{
	li minimum=0,damage = *prev,strength;
	for(int j=0;j<n;++j)
	{
		strength =*power;
		for(int i=n-1;i>0;--i)
		{
			if(damage <= d)
			return minimum;
			if(string[i]=='C')
			strength/=2;
			if(string[i]=='S'&& string[i-1]=='C')
			{
				swap(string+i,string+i-1);
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
		li d,damage=0,minimum,power=0;
		int length;
		char string[size];
		scanf("%ld%s",&d,string);
		length = str(string,&damage,&power);
		minimum=min(length,d,string,&damage,&power);
		printf("Case #%d: ",i);
		if(minimum == -1)
		printf("IMPOSSIBLE\n");
		else
		printf("%ld\n",minimum);
	}
	return 0;
}
