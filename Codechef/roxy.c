#include <stdio.h>

int main()
{
	/*char string[100000],*p;
	scanf("%s",string);
	p=string;
	while(*p!='\0')
	{
		printf("%c",18^(*p));	
		++p;
	}*/
	char c;
	scanf("%c",&c);
	printf("%c",(c+10)/2);
	
	return 0;
}
