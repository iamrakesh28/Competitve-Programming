#include<stdio.h>

struct A{
	int a,b;
};
int main()
{
	struct A a = {1,2};
	struct A b = a;
	printf("%d %d\n",b.a,b.b);
	return 0;
}
