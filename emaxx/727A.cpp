#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a,b,c;
	int cnt=0;
	scanf("%lld%lld",&a,&b);
	map <long long,int> mp;
	mp.insert({a,cnt});
	vector <long long> memo,path,l;
	queue <int> q;
	memo.push_back(a);
	q.push(cnt);
	cnt++;
	path.push_back(0);
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		c = memo[p];
		if(c == b) {
			printf("YES\n");
			int i = p;
			while(i) {
				l.push_back(i);
				i = path[i];
			}
			l.push_back(i);
			cout<<l.size()<<"\n";
			for(auto it=l.rbegin();it!=l.rend();++it)
				cout<<memo[*it]<<" ";
			cout<<endl;
			return 0;
		}
		if(2*c <= b && mp.count(2*c) == 0) {
			mp.insert({2*c,cnt});
			memo.push_back(2*c);
			path.push_back(p);
			q.push(cnt);
			cnt++;
		}
		if(10*c+1 <= b && mp.count(10*c+1) == 0) {
			mp.insert({10*c+1,cnt});
			memo.push_back(10*c+1);
			q.push(cnt);
			path.push_back(p);
			cnt++;
		}
	}
	cout<<"NO\n";
	return 0;
}
