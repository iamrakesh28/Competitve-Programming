#include <bits/stdc++.h>

#define SIZE 52

using namespace std;

int curID;

struct TrieNode{
	TrieNode *alpha[SIZE];
	bool end;
	int ID;
};

TrieNode *newNode(void)
{
	TrieNode *node = new TrieNode;
	node->end = false;
	for(int i=0;i<SIZE;++i)
	node->alpha[i] = NULL;
	return node;
}

void insert(TrieNode *root,string key)
{
	TrieNode *crawl = root;
	int index;
	for(int i = 0;i < key.length();++i)
	{
		if(isupper(key[i]))
		index = key[i] - 'A';
		else
		index = key[i] - 'a' + 26;
		if(crawl->alpha[index] == NULL)
		crawl->alpha[index] = newNode();
		crawl = crawl->alpha[index];
	}
	crawl->ID = curID++;
	crawl->end = true;
}

int search(TrieNode *root,string key)
{
	TrieNode *crawl = root;
	int index;
	for(int i=0;i < key.length(); ++i)
	{
		if(isupper(key[i]))
		index = key[i] - 'A';
		else
		index = key[i] - 'a' + 26;
		if(crawl->alpha[index] == NULL)
		{
			insert(root,key);
			return curID-1;
		}
		crawl = crawl->alpha[index];
	}
	if((crawl != NULL) && crawl->end == true)
	return crawl->ID;
	insert(root,key);
	return curID-1;
}

TrieNode *root;

vector <int> par,size;
int Root(int x)
{
	if(par[x] == x)
	return x;
	return Root(par[x]);
}

void join(int x,int y)
{
	x = Root(x);
	y = Root(y);
	if(x == y)
	return;
	if(size[x] > size[y])
	{
		par[y] = x;
		size[x] += size[y];
	}
	else
	{
		par[x] = y;
		size[y] += size[x];
	}
}

void Deallocate(TrieNode *root)
{
	for(int i=0;i<SIZE;++i)
	{
		if(root->alpha[i] != NULL)
		Deallocate(root->alpha[i]);	
	}
	delete [] root;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		curID = 0;
		int m;
		scanf("%d",&m);
		root = newNode();
		while(m--)
		{
			string f1,f2;
			cin>>f1>>f2;
			//cout<<f1<<" "<<f2<<endl;
			int id1 = search(root,f1);
			int id2 = search(root,f2);
			if(id1 < id2)
			{
				if(id1 >= par.size())
				{	
					par.push_back(id1);
					size.push_back(1);
				}
				if(id2 >= par.size())
				{ 
					par.push_back(id2);
					size.push_back(1);
				}
			}
			else
			{
				if(id2 >= par.size())
				{	
					par.push_back(id2);
					size.push_back(1);
				}
				if(id1 >= par.size())
				{ 
					par.push_back(id1);
					size.push_back(1);
				}

			}
			//cout<<id1<<" "<<id2<<endl;
			join(id1,id2);
			printf("%d\n",size[Root(id1)]);
		}
		par.clear();
		size.clear();
		//Deallocate(root);
	}
	return 0;
}
