#include <bits/stdc++.h>

#define M 1000
#define initial 4999


class coor{
	public:
	int row_,col_;
	int row_or,col_or;
	coor(int row, int col,int row_o,int col_o) : row_(row),col_(col),row_or(row_o),col_or(col_o) {}
};

class fill_co{
	public:
	int row,col;
	coor(int row, int col,) : row(row),col(col) {}
};
int find(set <coor> &mat,int x,int y)
{
	set <coor> :: iterator it;
	int i=1;
	for(it = mat.begin();it != mat.end();++it)
	{
		if((*it).row_ == y && (*it).col_ == x)
		return i;
		++i;
	}
	return 0;
}

int deploy(set <coor> &mat,int x,int y,int *prev,int row, int col,int *row_,int *col_)
{
	int length,val=find(mat,x,y);
	if(!val)
	{
		mat.insert(coor(y,x,row,col));
	}
	else
	{
		if(*prev-val==1)
		{
			matrix_fill(back,mat,row_,col_);
			return 1;
		}
	}
	*prev = val;

	return 0;
}
void matrix_fill(bool **back,set <coor> &mat,int *row, int *col)
{
	queue <fill_co> q;
	fill_co source(initial,initial);
	q.push(source);
	while(!q.empty())
	{
		fill_up p = q.front();
		q.pop();
		if(back[p.row][p.col] == false)
		{
			*row = p.row, *col = p.col;
			return ;
		}
		else
		{
			if(p.row-1>=0 && p.col -1>= 0 )
			{
				if(back[p.row-1][p.col-1] == false)
				{	
					*row = p.row-1, *col = p.col-1;				
				        return ;
				}
				else
				q.push(fill_up(p.row-1,q.col-1));
				
			}
			if(p.row-1>=0 && p.col +1< M )
			{
				if(back[p.row-1][p.col+1] == false)
				{	
					*row = p.row-1, *col = p.col+1;				
				        return ;
				}
				else
				q.push(fill_up(p.row-1,q.col+1));
				
			}if(p.row+1<M && p.col -1>= 0 )
			{
				if(back[p.row+1][p.col-1] == false)
				{	
					*row = p.row+1, *col = p.col-1;				
				        return ;
				}
				else
				q.push(fill_up(p.row+1,q.col-1));
				
			}if(p.row+1<M && p.col +1 < M )
			{
				if(back[p.row+1][p.col+1] == false)
				{	
					*row = p.row+1, *col = p.col+1;				
				        return ;
				}
				else
				q.push(fill_up(p.row+1,q.col+1));
				
			}if(p.col -1>= 0 )
			{
				if(back[p.row][p.col-1] == false)
				{	
					*row = p.row, *col = p.col-1;				
				        return ;
				}
				else
				q.push(fill_up(p.row,q.col-1));
				
			}if( p.col +1<M )
			{
				if(back[p.row][p.col+1] == false)
				{	
					*row = p.row, *col = p.col+1;				
				        return ;
				}
				else
				q.push(fill_up(p.row,q.col+1));
				
			}
			if(p.row+1<M)
			{
				if(back[p.row+1][p.col] == false)
				{	
					*row = p.row+1, *col = p.col;				
				        return ;
				}
				else
				q.push(fill_up(p.row+1,q.col));
			}
			if(p.row-1>=0 )
			{
				if(back[p.row-1][p.col] == false)
				{	
					*row = p.row-1, *col = p.col;				
				        return ;
				}
				else
				q.push(fill_up(p.row-1,q.col));
			}
		}
	}
}
void matrix(int *pos,bool **back)
{
	int result,row_,col_,prev;
	for(int i = initial- *pos; i<= initial + *pos;++i)
	{
		for(int j= initial - *pos; j<=initial + *pos;++j)
		{
			printf("%d %d\n",i+1,j+1);
			scanf("%d%d",&y,&x);
			back[i][j]=true;
			result = deploy(mat,x,y,&prev,i+1,j+1,&row_,&col_)
		}
	}
}

int main()
{	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		bool **back = (bool **)malloc(sizeof(bool*)*M);
		for(int i=0;i<M;++i)
		{
			back[i] = (bool *)malloc(sizeof(bool)*M);
			memset(bool[i],false,sizeof(bool)*M);
		}
		set <coor> mat;
		int x,y,area,length,pos=0;
		scanf("%d",&area);
	}
	return 0;
}
