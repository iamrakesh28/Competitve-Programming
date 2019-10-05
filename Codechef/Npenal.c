#include<stdio.h>
#include<string.h>
int fun1(char *goal, int *a, int *b)
{
	int c,i=0; char f;
	for(;((*a)-(*b))*((*a)-(*b))<(4-i/2)*(4-i/2);i+=2)
	{
		f=goal[i];
		sscanf(&f,"%d",&c);
		(*a)+=c;
		if(((*a)-(*b))*((*a)-(*b))>(3-i/2)*(3-i/2))
		return i+1;
		f=goal[i+1];
		sscanf(&f,"%d",&c);
		(*b)+=c;
	}	
	return i;

}
int fun2(char *goal, int *a, int *b)
{
	goal[20]=1;
	goal[21]=0;
	int c,i=10; char d;
	do{
		d=goal[i];
		sscanf(&d,"%d",&c);
		(*a)+=c;
		d=goal[i+1];
		sscanf(&d,"%d",&c);
		(*b)+=c;
		i+=2;
	}while((*a)-(*b)==0);
	return i;
}
int main()
{
	char goal[23];
	int a,b;
	gets(goal,24);
	while(strlen(goal)>0)
	{
		a=b=0;
		int val=fun1(goal,&a,&b);
		if(val<8)
		{
			if(a>b)
			printf("TEAM-A %d\n",val);
			else
			printf("TEAM-B %d\n",val);
		}
		else
		{
			val=fun2(goal,&a,&b);
			if(val<20)
			{
				if(a>b)
			         printf("TEAM-A %d\n",val);
			         else
			         printf("TEAM-B %d\n",val);
			}
			else
				printf("TIE\n");
		}
	gets(goal,24);
	}
	return 0;
}
