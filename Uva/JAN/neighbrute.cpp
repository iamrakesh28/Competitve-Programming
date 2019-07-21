#include <bits/stdc++.h>

using namespace std;

int mat[55][55],n,m;
int col[] = {-2,-1,-1,0,0,0,1,1,2};
int row[] = {0,-1,1,-2,2,0,-1,1,0};
bool val[9];

int isPossible(int r,int c)
{
	if(r >= 0 && r < n && c >=0 && c < m)
	return mat[r][c];
	return -1;
}
int next(bool *val)
{
	int r;
	for(r = 0; r < 9 ;++r)
	if(val[r] == false)
	break;
	return r;
}

void fill(bool *val,int i,int j)
{
	int v = -1;
	if(i-2 >= 0)
	v = mat[i-2][j]
	else if(j-2 >= 0)
	v = mat[i][j-2]
	else
	{
		v = next(val) + 1;
		val[v-1] = true;
	}
	if(j+2 < m)
	mat[i][j+2] = v;
	if(i+2 < n)
	mat[i+2][j] = v;
	if(i-1>=0 && j-1>=0)
	v = mat[i-1][j-1];
	else
	{
		v = next(val) + 1;
		val[v-1] = true;
	} 
	if(i+1<n && j+1<m)
	mat[i+1][j+1] = v;
}
int main()
{
	int q,num,k=-1;
	scanf("%d",&q);
	while(q--)
	{
		k=-1;
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
				if(mat[i][j] == -1)
				mat[i][j] = 1;
				memset(val,false,sizeof(bool)*9);
				int r;
				for(r = 0; r < 9 ;++r)
				{
					num = isPossible(row[r]+i,col[r]+j);
					if(num != -1)
					val[num-1] = true;
				}
				
				mat[i][j] = r+1;
				k = max(k,r+1);
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

