#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	int ver[1000][2]={0},hor[3000]={0};
	scanf("%d",&n); 
	int x,y;
	long int pair=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		hor[x+y]++;
		if(x>y)
		{
			ver[x-y][1]++;
		}
		else
			ver[y-x][0]++;
	}  
	for(int i=0;i<1000;++i)
	{
		pair+=(ver[i][0])*(ver[i][0]-1)/2;
		pair+=(ver[i][1])*(ver[i][1]-1)/2;
	}
	for(int i=0;i<3000;++i)
	{
		pair+=(hor[i])*(hor[i]-1)/2;
	}
	printf("%ld\n",pair);
    return 0;
}