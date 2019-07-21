#include <bits/stdc++.h>

using namespace std;

long int traversal(list <long int> *graph, long int i,bool *visit)
{
    long int cost=1;
    visit[i]=true;
    //cost++;
    //cout<<i<<"+";
    for(auto j=graph[i].begin();j!=graph[i].end();j++)
    {
                if(visit[*j] == false)
                cost+=traversal(graph,*j,visit);
                 //node[i].cities.pop_back();
    }
    
    return cost;
}

long int calculate(long int n,list <long int> *graph,long int road,long int lib,bool *visit)
{
    long int con=0,temp;
    for(long int i=0;i<n;++i)
    {
            if(visit[i] == false)
            {
                temp=traversal(graph,i,visit);
                //prlong intf("%d ",temp);
                con += (temp-1)*road;
                con += lib;
            }
        //prlong intf("%d ",temp);
            
    }
    return con;
}

int main()
    {
        long int q;
        scanf("%ld",&q);
        for(long int i=0;i<q;++i)
        {
            long int n,m,lib,road,cost;
            scanf("%ld%ld%ld%ld",&n,&m,&lib,&road);
            if((lib<road)||(m==0))
            {
                cost=n*lib;
                printf("%ld\n",cost);
		for(long int j=0;j<m;++j)
            	{
                long int x,y;
                scanf("%ld%ld",&x,&y);
		}
                continue;
            }
            list <long int> *graph;
            graph=new list <long int>[n];
            bool *visit=(bool *)malloc(n*sizeof(bool));
            memset(visit,false,sizeof(bool)*n);
            for(long int j=0;j<m;++j)
            {
                long int x,y;
                scanf("%d%d",&x,&y);
                graph[x-1].push_back(y-1);
                graph[y-1].push_back(x-1);
            }
            long int result=calculate(n,graph,road,lib,visit);
            printf("%ld\n",result);
            //free(visit);
        }
   
    return 0;
    }

