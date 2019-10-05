#include <stdio.h>

int main()
{
	int n,num;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		num=0;
		for(int j=0;j<5;++j)
		{
			int val;
			scanf("%d",&val);
			num+=val;
		}
		switch(num)
		{
			case 0:printf("Beginner\n"); break;
			case 1:printf("Junior Developer\n"); break;
			case 2:printf("Middle Developer\n"); break;
			case 3:printf("Senior Developer\n"); break;
			case 4:printf("Hacker\n"); break;
			case 5:printf("Jeff Dean\n"); break;
		}
	}
	return 0;
}