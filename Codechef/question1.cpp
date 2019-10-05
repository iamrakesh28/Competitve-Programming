#include <bits/stdc++.h>

using namespace std;

int row_check(int *row, int h,int R,int req, vector <int> &row_)
{
	int count=0,r_w=0;
	for(int i=0 ;i< R;++i)
	{
		r_w+=row[i];
		if(r_w == req)
		{
			r_w=0;
			row_.push_back(i);
			//j++;
			count++;
		}
		else if(r_w > req)
		{
			return 0;
		}
		//printf(" %d =",count);
	}
	if(r_w == 0)
	{
		count--;
	}
	if(count == h)
	return 1;
	else
	return 0;
}
int check_(int single,int row_l,int col_l,int row_u,int col_u,int **mat)
{
	int total=0;
	for(int i=row_l;i<=row_u;++i)
	{
		for(int j = col_l;j<=col_u;++j)
		{
			if(mat[i][j])
			total++;
		}
	}
	if(total == single)
	return 1;
	return 0;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1 ; i<=q;++i)
	{
		int R,c,h,v,total=0,diners,check=0,row_req,col_req;
		char ch;
		scanf("%d%d%d%d",&R,&c,&h,&v);
		int *row = (int *)calloc(R,sizeof(int));
		int *col = (int *)calloc(c,sizeof(int));
		int **mat = (int **)malloc(R*sizeof(int*));
		vector <int> row_;
		vector <int> col_;
		for(int j =0 ;j <  R;++j)
		{
			mat[j] = (int *)malloc(c*sizeof(int));
			for(int k = 0 ;k<c;++k)
			{
				scanf(" %c",&ch);
				if(ch == '@')
				{
					mat[j][k] =1;
					total++;
					row[j]++;
					col[k]++;
				}
				else
				mat[j][k] =0;
			}
		} 
		diners = (h+1)*(v+1);
		if(total == 0)
		{
			printf("Case #%d: POSSIBLE\n",i);
			continue;
		}
		if(total%diners)
		{
			printf("Case #%d: IMPOSSIBLE\n",i);
			continue;
		}
		row_req = total/(h+1);
		int r_c = row_check(row,h,R,row_req,row_);
		//printf("%d=",row_[0]);
		if(r_c)
		{
			col_req = total/(v+1);
			int c_c = row_check(col,v,c,col_req,col_);
			if(c_c)
			{
				//printf("%d=",col_[0]);
				int r_prev=0,c_prev=0;
				for(int j =0 ;j < row_.size();++j)
				{
					c_prev =0;
					for(int k =0 ;k < col_.size();++k)
					{
						if(!check_(total/diners,r_prev,c_prev,row_[j],col_[k],mat))
						{
							//printf("%d %d=",row_[j],col_[k]);
							printf("Case #%d: IMPOSSIBLE\n",i);
							check =1;
							break;
						}
						c_prev =col_[k]+1;
					} 
					if(check)
					break;
					r_prev = row_[j]+1;
				} 
				if(check)
				continue;
				else
				printf("Case #%d: POSSIBLE\n",i);
			}
			else
				printf("Case #%d: IMPOSSIBLE\n",i);
		}
		else
		{
			
			printf("Case #%d: IMPOSSIBLE\n",i);
		}
		
	}
	return 0;
}
