#include <stdio.h>
#include <string.h>

int main()
{
	char num[20];
	scanf("%s",num);
	int l1 = strlen(num);
	//printf("%d %d %d\n",l1,l2,l3);
	int count=0;
	for(int i=0;i<l1;++i)
	{
		if(num[i] == '4' || num[i] == '7')
		count++;
	}
	if(!count)
	{
		printf("NO\n"); return 0;
	}

	while(count)
	{
		int rem = count%10;
		if(rem != 4 && rem != 7)
		{
			printf("NO\n"); return 0;
		}
		count = count/10;
	}
	printf("YES\n");
	return 0;
}