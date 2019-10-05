#include <stdio.h>
#include <stdlib.h>

#define cost(x) (200 + x)

void fill(int bead[][401],int s,int g,int q,int r,int d)
{
	for(int i=0;i<=100;++i )
	{
		for(int j=0;j<=400;++j)
		{
			bead[i][j]=-1;
		}
	}
	bead[1][cost(-2)]=s;
	bead[1][cost(-1)]=g;
	bead[1][cost(0)]=q;
	bead[1][cost(1)]=r;
	bead[1][cost(2)]=d;
	for(int i=2;i<=100;++i )
	{
		for(int j=0;j<=400;++j)
		{
			if(bead[i-1][j]!= -1)
			{
							
				if(bead[i][cost(j-200-2)]>bead[i-1][j]+s || bead[i][cost(j-200-2)]== -1)
				bead[i][cost(j-200-2)]=bead[i-1][j]+s;
				if(bead[i][cost(j-200-1)]>bead[i-1][j]+g || bead[i][cost(j-200-1)]== -1)
				bead[i][cost(j-200-1)]=bead[i-1][j]+g;
				if(bead[i][cost(j-200+0)]>bead[i-1][j]+q || bead[i][cost(j-200+0)]==-1)
				bead[i][cost(j-200+0)]=bead[i-1][j]+q;
				if(bead[i][cost(j-200+1)]>bead[i-1][j]+r || bead[i][cost(j-200+1)]== -1)
				bead[i][cost(j-200+1)]=bead[i-1][j]+r;
				if(bead[i][cost(j-200+2)]>bead[i-1][j]+d || bead[i][cost(j-200+2)]== -1)
				bead[i][cost(j-200+2)]=bead[i-1][j]+d;
			}
		}
	}
}

int main()
{
	int s,g,q,r,d,t;
	scanf("%d%d%d%d%d%d",&s,&g,&q,&r,&d,&t);
	int bead[101][401];
	fill(bead,s,g,q,r,d);
	bead[0][200] = 0;
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",bead[x][cost(y)]);
	}
	return 0;
}

