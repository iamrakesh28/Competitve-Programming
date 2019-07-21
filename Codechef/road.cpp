#include <bits/stdc++.h>

using namespace std;

struct city{
    int visted;
    vector <int> cities;
};

int traversal(struct city *node, int i)
{
    int cost=0;
       
    if(node[i].visted==0)
    {
             node[i].visted=1;
             cost++;
             for(int j=0;j<node[i].cities.size();j++)
             {
                cost+=traversal(node,node[i].cities[j]);
             }
    }
    return cost;
}

int calculate(int n, struct city *node,int road,int lib)
{
    int con=0,temp;
    for(int i=0;i<n;++i)
    {
        temp=traversal(node,i);
        //printf("%d ",temp);
        if(temp>1)
        {
            con+=road*(temp-1);

        }
        if(temp)
        con+=lib;
    }
    return con;
}

int main()
    {
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;++i)
        {
            int n,m,lib,road,cost;
            scanf("%d%d%d%d",&n,&m,&lib,&road);
            if(lib<road)
            {
                cost=n*lib;
                printf("%d\n",cost);
                continue;
            }
            //vector <vector <int> > graph(n);
            struct city *node =(struct city *)calloc(n,sizeof(struct city));
            for(int j=0;j<m;++j)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                node[x-1].cities.push_back(y-1);
                node[x-1].visted=0;
                node[y-1].visted=0;
                node[y-1].cities.push_back(x-1);
            }
            int result=calculate(n,node,road,lib);
            printf("%d\n",result);
            free(node);
        }
   
    return 0;
    }
