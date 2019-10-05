#include <bits/stdc++.h>

using namespace std;

int main()
{
	int f,r;
	while(scanf("%d%d",&f,&r) != EOF && f)
	{
		vector <int> fteeth(f);
		vector <int> rteeth(r);
		vector <float> pair;
		float drive = 0;
		for(int i=0;i<f;++i)
		cin>>fteeth[i];
		for(int i=0;i<r;++i)
		cin>>rteeth[i];
		for(int i=0;i<f;++i)
		{
			for(int j=0;j<r;++j)
			pair.push_back((float)rteeth[j]/fteeth[i]);
		}
		sort(pair.begin(),pair.end());
		for(int i=1;i<pair.size();++i)
		drive = max(drive,pair[i]/pair[i-1]);
		printf("%0.2f\n",drive);
	}
	return 0;
}
