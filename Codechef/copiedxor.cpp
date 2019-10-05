#include <bits/stdc++.h>
using namespace std;

#define ll long int

struct Node{
    ll lC,rC;
    Node *right, *left;
};

Node *newNode()
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->lC = temp->rC = 0;
    	temp->left = temp->right = NULL;
    	return temp;
}

Node* insert(Node *root, ll n, ll level){
    if(level == -1){return root;}
    
    if(n&(1<<level)){
        root->rC += 1;
        if(!root->right){
            root->right = newNode();
        }
        root->right = insert(root->right, n, level-1);
    }
    else{
        root->lC += 1;
        if(!root->left){
            root->left = newNode();
        }
        root->left = insert(root->left, n, level-1);
    }
    
    return root;
}

ll query(Node *root, ll n, ll level, ll k){
    if(!root || level == -1){return 0;}
    
    bool p = (n&(1<<level));
    bool q = (k&(1<<level));
    
    if(q){
        if(!p){return root->lC+query(root->right, n, level-1, k);}
        else{return root->rC+query(root->left, n, level-1, k);}
    }
    else{
        if(!p){return query(root->left,n,level-1,k);}
        else{return query(root->right,n,level-1,k);}
    }
}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t, n, k, temp, ans, x;
        ans = temp = x = 0;
        cin>>n>>k;
        Node *root = newNode();
	ll maxEle = k;
	ll *arr = new ll[n];
	for(int i=0;i<n;++i)
	cin>>arr[i];
    	for(int i = 0; i < n; i++)
        maxEle = max(maxEle, arr[i]);
    	int height = (int)ceil(1.0 * log2(maxEle)) + 1;
        insert(root, x, height-1);
        for(ll i = 0; i < n; i++){
            temp = arr[i];
            x ^= temp;
            ans += query(root, x, height-1, k);
            insert(root, x, height-1);
        }
        cout<<ans<<endl;
	return 0;
}
