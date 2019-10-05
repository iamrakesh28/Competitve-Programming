#include<stdio.h>
#include<string.h>
#include<math.h>

int goalc(char *kick, int *ga, int *gb)
{
	int i=0,c;
	char a;
	unsigned int com;
	for(;i<9;i+=2)
	{	
		a=kick[i];
		sscanf(&a,"%d",&c);
		(*ga)+=c;
		//printf("\t%d",com);
		//com=pow((*ga)-(*gb),2);
		//if(com>pow((8-i)/2,2))
		//return i+1;
		a=kick[i+1];
		sscanf(&a,"%d",&c);
		(*gb)+=c;
		com=pow((*ga)-(*gb),2);
		if(com>pow((8-i)/2,2))
		return i+1;
	}
	com=(*ga)-(*gb);
	for(i=10;i<19;i+=2)
	{
		a=kick[i];
		sscanf(&a,"%d",&c);
		(*ga)+=c;
		a=kick[i+1];
		sscanf(&a,"%d",&c);
		(*gb)+=c;
		if((*ga)-(*gb)!=0)
		return i+2;		
	}
	return 0;
}

int main()
{

	char kick[21];
	int ga=0,gb=0;
	gets(kick,20);
	while(strlen(kick)>0)
	{
		ga=0;gb=0;
		int dec=goalc(kick,&ga,&gb);
		if(dec)
		{
		if(ga>gb)
		printf("TEAM-A %d\n",dec);
		else
		printf("TEAM-B %d\n",dec);
		}
		else
		printf("TIE\n");
		gets(kick,20);
	}
	return 0;
}