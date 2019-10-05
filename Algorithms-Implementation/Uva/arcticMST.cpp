#include <bits/stdc++.h>

#define mk(x) make_pair(x)
#define pb(x) push_back(x)
#define INF 100000

using namespace std;

typedef pair <float,int> ipair;

float **distance(int p,int *x,int *y)
{
	float **dist = new float*[p];
	for(int i=0;i<p;++i)
	{
		dist[i] = new float[p];
		for(int j=0;j<p;++j)
		{
			dist[i][j] = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
		}
	}
	return dist;
}

float Prim(float **dist,int p,int s)
{
	vector <float> minimum(p,INF);
	set <ipair> mst;
	mst.insert(make_pair(0,0));
	minimum[0] = 0;
	bool *visited = new bool[p];
	memset(visited,false,sizeof(bool)*p);
	while(!mst.empty())
	{
		ipair node = *(mst.begin());
		mst.erase(*(mst.begin()));
		int u = node.second;
		visited[u] = true;
		for(int i=0;i<p;++i)
		{
			if(visited[i] == false && minimum[i] > dist[u][i])
			{
				if(minimum[i] != INF)
				mst.erase(mst.find(make_pair(minimum[i],i)));
				minimum[i] = dist[u][i];
				mst.insert(make_pair(minimum[i],i));
			}
		}
	}
	float D=0;
	sort(minimum.begin(),minimum.end());
	D = minimum[p-s] ;
	return D;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int s,p;
		scanf("%d%d",&s,&p);
		int *x,*y;
		x = new int[p];
		y = new int[p];
		for(int i=0;i<p;++i)	
		scanf("%d%d",x+i,y+i);
		float **dist = distance(p,x,y);
		/*for(int i=0;i<p;++i)
		{
			for(int j=0;j<p;++j)
			cout<<dist[i][j]<<" ";
			cout<<endl;
		}*/
		float D = Prim(dist,p,s);
		printf("%0.2f\n",D);
	}
	return 0;
}
