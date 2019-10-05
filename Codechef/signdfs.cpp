
    #include <bits/stdc++.h>
     
    #define ul long long int
     
    using namespace std;
     
    struct tree{
    	long long int min;
    	vector <int> *seq;
    };
     
    ul minimum(ul a,ul b,int *num)
    {
    	if(a<b)
    	{
    		*num=1;
    		return a;
    	}
    	*num=2;
    	return b;
    }
     
     
    class Graph{
    	
    	public:
    	int V;
    	bool *visited;
    	list <int> *adj;
    	Graph(int,bool *);
    	void addEdge(int,int);
    	void DFS(long long int*,int,int,int,tree *,ul *);
    };
     
    Graph::Graph(int V,bool *pt)
    {
    	this->V=V;
    	adj=new list<int>[V];
    	visited=pt;
    }
     
    void Graph::addEdge(int v,int w)
    {
    	adj[v].push_back(w);
    	//adj[w].push_back(v);
    }
    void Graph::DFS(long long int *arr,int n,int leaf,int pos,tree *node,ul *sum)
    {
    	//visited[leaf]=true;
    	int num;
    	vector <int> *pt;
    	list <int> :: iterator it,ite;
    	if(adj[leaf].size()==0)
    	{
    		pt=node[leaf].seq = new vector<int>[1];
    		node[leaf].min=sum[n]-2*arr[(2*(leaf-1))+pos];
    		pt[0].push_back((2*(leaf-1))+pos);
    		return;
    	}
    	for(it=adj[leaf].begin();it!=adj[leaf].end();++it)
    	{
    		//if(i>=2)
    		//break;
    		//if((*it)>leaf)
    		{
    			DFS(arr,n,*it,pos,node,sum);
    		}
    	}
    	it=adj[leaf].begin();
    	if(adj[leaf].size()==1)
    	{
    		pt= node[leaf].seq = node[*it].seq;
    		node[leaf].min=node[*it].min-2*arr[(2*(leaf-1))+pos];//sum[n]-2*arr[2*(2*leaf)+pos];
    		pt[0].push_back((2*(leaf-1))+pos);
    		return;
    	}
    	ite = ++it;
    	it--;
    	if(leaf>0)
    	node[leaf].min=minimum(node[*it].min,node[*ite].min,&num)-2*arr[(2*(leaf-1))+pos];
    	else
    	node[leaf].min=minimum(node[*it].min,node[*ite].min,&num);
    	//printf("%d=",num);
    	if(num==1)
    	{
    		pt=node[leaf].seq=node[*(it)].seq;
    		if(leaf>0)
    		pt[0].push_back((2*(leaf-1))+pos);
    	}
    	else
    	{
    		pt=node[leaf].seq=node[*ite].seq;
    		if(leaf>0)
    		pt[0].push_back((2*(leaf-1))+pos);
    	}
    	return;
    }
     
    void infinity(long long int *arr,int n,int pos,int count,ul *sum)
    {
    	//printf("%d=%d=",pos,count);
    	count++;
    	bool *visited = new bool[count];
    	memset(visited,false,sizeof(bool)*count);
    	tree *node = new tree[count];
    	Graph obj(count,visited);
    	obj.addEdge(0,1);
    	obj.addEdge(0,2);
    	for(int i=1;i<count;++i)
    	{
    		if(i+2<count)
    		obj.addEdge(i,i+2);
    		else
    		break;
    		if(i+3<count)
    		obj.addEdge(i,i+3);
    	}
    	obj.DFS(arr,n,0,pos,node,sum);
    	for(int i=0;i<node[0].seq[0].size();++i)
    	{
    		int val=node[0].seq[0][i];
    		arr[val]=(-1)*arr[val];
    	}
    }
     
    void peak(long long int *arr,bool *mark,int n,ul *sum)
    {
    	long long int val;
    	if(arr[0]>=arr[1])
    	mark[0]=false;
    	else
    	mark[0]=true;
    	for(int i=1;i<n-1;++i)
    	{
    		if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
    		mark[i]=true;
    		else
    		mark[i]=false;			
    	}
    	if(arr[n-1]<arr[n-2])
    	mark[n-1]=true;
    	else
    	mark[n-1]=false;
    	for(int i=0;i<n;++i)
    	{
    		if(mark[i]==true)
    		{
    			if(i<n-2 && mark[i+2]==true)
    			{
    				val=sum[i+3]-sum[i]-2*arr[i]-2*arr[i+2];
    				if(val<=0)
    				continue;
    			}
    			if(i>=2 && mark[i-2]==true)
    			{
    				val=sum[i+1]-sum[i-2]-2*arr[i]-2*arr[i-2];
    				if(val <= 0)
    				{
    					continue;
    				}
    			}
    			mark[i]=false;
    			arr[i]=(-1)*arr[i];
    		}	
    	}
    }
     
    int main()
    {
    	int q;
    	scanf("%d",&q);
    	while(q--)
    	{
    		int n,count=0,pos;
    		scanf("%d",&n);
    		long long int *arr = new long long int[n];
    		bool *mark = new bool[n];
    		ul *sum = (ul*)malloc((n+1)*sizeof(ul));
    		scanf("%lld",arr);
    		sum[0]=0;
    		sum[1] = arr[0];		
    		for(int i=1;i<n-1;++i)
    		{
    			scanf("%lld",arr+i);
    			sum[i+1] = arr[i]+sum[i];
    		}
    		scanf("%lld",arr+n-1);
    		sum[n] = arr[n-1]+sum[n-1];
    		peak(arr,mark,n,sum);
    		int j;	
    		for(j=0;j<n;++j)
    		{
    			if(mark[j]==true)
    			{
    				count++;
    				j++;
    			}
    			else if(j>=2 && mark[j-2]==true)
    			{
    				pos=j-2*(count);
    				infinity(arr,n,pos,count,sum);
    				count=0;
    			}
    		}
    		if(j>=2 && mark[j-2]==true)
    		{
    			pos=j-2*(count);
    			infinity(arr,n,pos,count,sum);
    			count=0;
    		}
    		for(int i=0;i<n;++i)
    		{
    			printf("%lld ",arr[i]);
    		}
    		printf("\n");
    	}
    	
    }


