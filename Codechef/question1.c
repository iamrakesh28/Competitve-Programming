#include <bits/stdc++.h>

using namespace std;

int row_check(int *row, int h,int R,int req)
{
	int count=0,r_w=0,j=0;
	for(int i=0 ;i< R;++i)
	{
		r_w+=row[i];
		if(r_w == req)
		{
			r_w=0;
			j++;
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
		for(int j =0 ;j <  R;++j)
		{
			for(int k = 0 ;k<c;++k)
			{
				scanf(" %c",&ch);
				if(ch == '@')
				{
					total++;
					row[j]++;
					col[k]++;
				}
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
		for(int j =0 ;j <  R && j < c;++j)
		{
				if(row[j] != col[j])
				{
					check =1;
					break;
				}
		} 
		if(!check)
		{
			printf("Case #%d: IMPOSSIBLE\n",i);
			continue;
		}
		row_req = total/(h+1);
		int r_c = row_check(row,h,R,row_req);
		if(r_c)
		{
			col_req = total/(v+1);
			int c_c = row_check(col,v,c,col_req);
			if(c_c)
			{
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
