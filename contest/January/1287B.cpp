    #include <iostream>
    #include <unordered_map>
    #include <string>
    #include <vector>
     
    using namespace std;
     
    int main() {
     
    	int n, k, ans = 0, cnt = 0;
    	scanf("%d%d", &n, &k);
    	unordered_map <string, int> mp;
    	vector <string> v(n);
    	char ch = getchar();
    	for (int i = 0; i < n; ++i) {
    		string s;
    		//cin>>s;
    		for (int j = 0; j < k; ++j) {
    			ch = getchar();
    			s = s + ch;
    		}
    		//cout<<s<<endl;
    		ch = getchar();
    		mp[s] = i;
    		v[i] = s;
    		//auto it = mp.find(s);
    		//if (mp.find(s) != mp.end())
    		//	cout<<"hello\n";
    		//s = it;
    		//cout<<(*it)<<endl;
    	}
    	for (int i = 0; i < n - 1; ++i) {
    		for (int j = i + 1; j < n; ++j) {
    			string s = "";
    			for (int m = 0; m < k; ++m) {
    				if (v[i][m] == v[j][m])
    					s = s + v[i][m];
    				else {
    					if (v[i][m] != 'S' && v[j][m] != 'S')
    						s = s + 'S';
    					else if (v[i][m] != 'E' && v[j][m] != 'E')
    						s = s + 'E';
    					else
    						s = s + 'T';
    				}
    			}
    			//cout<<s<<endl;
    			if (mp.find(s) != mp.end())
    				cnt++;
    		}
    	}
    	printf("%d\n", cnt / 3);
    	return 0;
    }
