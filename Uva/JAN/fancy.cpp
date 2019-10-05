#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char string[105];

int main()
{
	int q;
	char clear;
	scanf("%d",&q);
	while(q--)
	{
		clear = getchar();
		scanf("%[^\n]s",string);
		int len = strlen(string);
		bool found = false;
		for(int i=0;i<len-2;++i)
		{
			if(string[i] == 'n' && i > 0 && string[i-1] == ' ')
			{
				if(i == len-3 && strcmp(string+i,"not") == 0)
				found = true;
				else if(i != len-3)
				{
					if(string[i+1] == 'o' && string[i+2] == 't' && string[i+3] == ' ')
					found = true;
				}
				
			}
			else if(string[i] == 'n' && i == 0)
			{
				if(i == len-3 && strcmp(string+i,"not") == 0)
				found = true;
				else if(i != len-3)
				{
					if(string[i+1] == 'o' && string[i+2] == 't' && string[i+3] == ' ')
					found = true;
				}
			}
			if(found)	
			break;
		}
		if(found)
		printf("Real Fancy\n");
		else
		printf("regularly fancy\n");
	}
	return 0;
}
