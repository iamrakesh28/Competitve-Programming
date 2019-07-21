#include <bits/stdc++.h>

using namespace std;

struct Grid{
	int height,i,j;
};

bool compare(Grid &a, Grid &b)
{
	return (a.height < b.height);
}
int mat[100][100],hill[100][100];
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int r,c;
		string name;
		cin>>name>>r>>c;
		vector <Grid> grid;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				mat[i][j] = 1;
				Grid p;
				cin>>p.height;
				p.i = i;
				p.j = j;
				grid.push_back(p);
				hill[i][j] = p.height;
			}
		}
		sort(grid.begin(),grid.end(),compare);
		for(auto it = grid.begin();it != grid.end();++it)
		{
			Grid p = *(it);
			int height = p.height;
			if(p.j >= 1 && hill[p.i][p.j-1] > height)
			{
				mat[p.i][p.j-1] = max(mat[p.i][p.j-1],mat[p.i][p.j]+1);
			}
			if(p.j+1 < c && hill[p.i][p.j+1] > height)
			{
				mat[p.i][p.j+1] = max(mat[p.i][p.j+1],mat[p.i][p.j]+1);
			}
			if(p.i >= 1 && hill[p.i-1][p.j] > height)
			{
				mat[p.i-1][p.j] = max(mat[p.i-1][p.j],mat[p.i][p.j]+1);
			}
			if(p.i+1 < r && hill[p.i+1][p.j] > height)
			{
				mat[p.i+1][p.j] = max(mat[p.i+1][p.j],mat[p.i][p.j]+1);
			}
		}
		int longest = 1;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			longest = max(longest,mat[i][j]);
		}
		cout<<name<<": "<<longest<<"\n";
	}
	return 0;
}
