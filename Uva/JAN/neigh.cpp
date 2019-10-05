#include <bits/stdc++.h>

using namespace std;

int mat[55][55],n,m;
int col[] = {-2,-1,-1,0,0,1,1,2};
int row[] = {0,-1,1,-2,2,-1,1,0};
bool val[8];

int isPossible(int r,int c)
{
	if(r >= 0 && r < n && c >=0 && c < m)
	return mat[r][c];
	return -1;
}

int main()
{
	int q,num,k;
	scanf("%d",&q);
	while(q--)
	{
		k = -1;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			mat[i][j] = -1;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				memset(val,false,sizeof(bool)*8);
				int r,num=-1;
				for(r = 0; r < 8 ;++r)
				{
					num = isPossible(row[r]+i,col[r]+j);
					if(num != -1)
					val[num-1] = true;
				}
				if(k != -1)
				{
					if(val[k-1] == false)
					num = k;
				}
				else
					num = 1;
				if(num == -1)
				{
					for(r = k-1; r >= 0 ;--r)
					if(val[r] == false)
					{
						num = r+1;
						break;
					}
					if(num == -1)
					num = k+1;
				}
				mat[i][j] = num;
				k = max(k,num);
			}
		}
		printf("%d\n",k);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			printf("%d ",mat[i][j]);
			printf("\n");
		}
	}
	return 0;
}
