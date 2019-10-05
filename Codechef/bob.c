#include <stdio.h>

int comp(char *test)
{
	int b=0,o=0;
	for(int i=0;i<3;++i)
	{
		if(test[i] == 'b')
		b++;
		else if(test[i] == 'o')
		o++;
	}
	if(b==2 && o == 1)
	return 1;
	return 0;
}

int perm(char *up,char *down,char *test,int start)
{
	if(start == 3)
	return comp(test);
	test[start] = up[start];
	if(perm(up,down,test,start+1))
	return 1;
	test[start] = down[start];
	if(perm(up,down,test,start+1))
	return 1;
	return 0;
}

int main()
{
	int q;
	char up[4],down[4],test[4];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s %s",up,down);
		if(perm(up,down,test,0))
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
