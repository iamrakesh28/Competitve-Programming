#include <stdio.h>

#define max 1000000000000000000
int main()
{
 double sum=90.50;
  unsigned long long int cur,prev,num=10,rem,q;
	int count =1,i=0;
       prev = sum*num;
        num *= 10;
      cur = sum*num;
while(prev*10 != cur &&  cur <= max)
{
	prev = cur;
	num *= 10;
	cur = sum*num;
	count++;
	printf("%llu\n",prev);
}
//printf("%llu %llu %llu\n",prev,cur,count);
while(i < count-2)
{
	rem = prev % 10;
	prev = prev/10;
	if(rem >= 5)
	{
		prev++;
	}
	++i;
	//printf("%llu %llu\n",i,count-2);
}
	int len=0;
    q=prev;
	while(q != 0)
	{
		q = q / 10;
		len++;
	}
	if(len == 4 )
	printf("%0.2f\n",prev/100.0);
	else if(len == 3)
	printf("%0.2f\n",prev/10.0);
       // sum = 90.345;
return 0;
}
