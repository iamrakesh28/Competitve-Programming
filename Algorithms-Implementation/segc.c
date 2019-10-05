#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
                     
                    #define MN -10
                    
                     
                   typedef struct Element{
                    	long long int index;
                    	  long long int val,key;
                    } Element;
                     
             
                     
			void merge(Element *arr, long long int l, long long int m, long long int r)
{
     long long int i, j, k;
     long long int n1 = m - l + 1;
     long long int n2 =  r - m;
    Element L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
	L[i] = arr[l + i];
	L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
	   R[j] = arr[m + 1+ j];
	   R[j] = arr[m + 1+ j];
    }
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].val <= R[j].val)
        {
            arr[k] = L[i];
	    //arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k] = R[j];
	    //arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
	//arr[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
	//arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
void mergeSort(Element *arr, long long int l, long long int r)
{
    if (l < r)
    {
         long long int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
                    //long long int getMid(long long int s, long long int e) {  return s + (e -s)/2;  }
                     
                    long long int left(long long int i,long long int k)
                    {
                    	if(i-k > 0)
                    	return i-k;
                    	return 0;
                    }
                    long long int right(long long int n,long long int k,long long int i)
                    {
                    	if(i+k < n)
                    	return i+k;
                    	return n-1;
                    }
                     
                      long long int maxm(   long long int a,   long long int b) {  return a>b?a:b;  }
                     
                    void updateValue(Element *arr, Element* st, long long int ss, long long int se,long long int index,   long long int value, long long int node)
                    {
                        	if (index < ss || index > se) 
                        	    return; 
                        	if(ss == se) 
                        	{   
                            	arr[index].key = value;
                            	st[node].key = value;
                    		st[node].index = arr[index].index;
                        	}
                        	else 
                    	{
                                long long int mid = ss + (se - ss)/2;
                                 
                                	if(index >= ss && index <= mid)
                                	   updateValue(arr, st, ss, mid, index,value, 2 * node + 1);
                                	else
                                	   updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2);
                    	    	if(st[2 * node + 1].key > st[2 * node + 2].key)
                    			st[node] = st[2*node+1];
                               	else if(st[2 * node + 1].key < st[2 * node + 2].key)
                    			st[node] = st[2*node+2];
                    		else if(st[2 * node + 1].val < st[2 * node + 2].val)
                    			st[node] = st[2*node+1];
                    		else
                    			st[node] = st[2*node+2];
                        }
                        return;
                    }
                    Element MaxUtil(Element* st, long long int ss, long long int se, long long int l, long long int r, long long int node)
                    {
                        	if(l <= ss && r >= se)
                            return st[node];
                        	if(se < l || ss > r)
                        	{	
                    		Element node;
                    		node.key = MN;
                            	return node;
                        	}
                        	long long int mid = ss + (se - ss)/2;//getMid(ss, se);
                        	Element left = MaxUtil(st, ss, mid, l, r, 2*node+1);
                        	Element right = MaxUtil(st, mid+1, se, l, r, 2*node+2);
                        	if(left.key > right.key)
                    	return left;
                    	else if(left.key < right.key)
                    	return right;
                    	else if(left.val < right.val)
                    	return left;
                    	return right;
                    	
                    }/*
                    Element getMax(Element* st, long long int n, long long int l, long long int r)
                    {
                        	return MaxUtil(st, 0, n - 1, l, r, 0);
                    }*/
                    Element constructSTUtil(Element *arr, long long int ss, long long int se, Element *st, long long int si)
                    {
                        	if (ss == se)
                        	{
                            	st[si] = arr[ss];
                            	return arr[ss];
                        	}
                        	long long int mid = ss + (se - ss)/2;//getMid(ss, se);
                    	Element left = constructSTUtil(arr, ss, mid, st, si*2+1);
                    	Element right = constructSTUtil(arr, mid+1, se, st, si*2+2);
                       	if(left.key > right.key)
                    	st[si] = left;
                    	else if(left.key < right.key)
                    	st[si] = right;
                    	else if(left.val < right.val)
                    	st[si] = left;
                    	else
                    	st[si] = right;
                            return st[si];
                    }
                    Element *constructST(Element *arr, long long int n,long long int max_size)
                    { 
                        	Element *st = (Element  *)malloc(sizeof(Element)*max_size); 
                        	constructSTUtil(arr, 0, n-1, st, 0);
                    	return st;
                     }
                      
                      long long int smallest(long long int n,long long int k,Element *element,  long long int index,Element *st)
                    {
                    	Element node = MaxUtil(st,0, n-1,left(element[index].index,k), right(n,k,element[index].index),0);
                    	if(node.val != element[index].val || node.index == element[index].index || (node.key == 0))
                    	return node.key + 1;
                    	return node.key;
                    }
                     
                    bool possible(long long int k,long long int n,Element *element,   long long int s,Element *arr,long long int max)
                    {
                    	   //long long int sum=0;
			 long long int sum=0,num,max_small;
                    	 long long int start = 0,i;
                    	arr[element[0].index].key = 1;
                    	Element *st = constructST(arr, n,max);
                    	max_small = 1;
                    	//long long int i;
			//num = smallest(n,k,element,0,st);
                    	//updateValue(arr, st, 0, n - 1, element[0].index, num, 0);
                    	for(i=1;i<n;++i)
                    	{
                    		num = smallest(n,k,element,i,st);
                    		updateValue(arr, st, 0, n - 1, element[i].index, num, 0);
                    		if(element[i].val == element[i-1].val)
                    		{
                    			max_small = maxm(max_small,num);
                    		}
                    		else
                    		{
                    			sum = sum + (i-start)*max_small;
                    			start = i;
                    			max_small = num;
					if(sum  > s)
					{
						for(long long int j=0;j<=i;++j)
                    				arr[element[j].index].key = 0;
						return false;
					}
                    		}
                    	}
			sum = sum + (i-start)*max_small;
                    	for(i=0;i<n;++i)
                    	arr[i].key = 0;
                    	free(st);
			//sum-=n;
                    	if(sum<=s)
                    	return true;
                    	return false;
                    }
                     
                    long long int solve(long long int n,   long long int s,Element *element,Element *arr,long long int max)
                    {
                    	long long int begin=0,end=n,middle,check=0;
                    	while(begin<=end)
                    	{
                    		middle = (begin+end)/2;
                    		if(possible(middle,n,element,s,arr,max))
                    		{
                    			begin = middle+1;
                    			check = 1;
                    		}
                    		else
                    		{
                    			end = middle-1;
                    			check = 0;
                    		}
                    	}
                    	if(check)
                    	return middle+1;
                    	return middle;
                    }
              /*       inline void scanint(  long long int &x)

	{
    register  int c = getchar_unlocked();

    x = 0;


    for(;((c<48 || c>57));c = getchar_unlocked());

    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}

}
*/
                     int main()
                    {
                    	int q;
                    	scanf("%d",&q);
                    	/*Element *element = new Element[100000];
                    	Element *arr = new Element[100000];*/
                    	Element *element=(Element *)malloc(sizeof(Element)*1000000);
                    	Element *arr=(Element *)malloc(sizeof(Element)*1000000);
                    	while(q--)
                    	{
                    		long long int n;
                    		  long long int s,x;
                    		scanf("%ld%ld",&n,&s);
                    		for(long long int i=0;i<n;++i)
                    		{
                    			//scanint(x);
					scanf("%lld",&x);
                    			element[i].index = i;
                    			arr[i].key = 0;
                    			arr[i].val = element[i].val = x;
                    			arr[i].index = element[i].index;
                    			
                    		}
				mergeSort(element,0,n-1);
				
                    		//sort(element,element + n,compare);
                    		//arr[element[0].index].key = 1;
                    		 x = (long long int)(ceil(log2(n))); 
                        	long long int max_size = 2*(long long int)pow(2, x) - 1;
                    		long long int num = solve(n,s,element,arr,max_size);
                    		printf("%lld\n",num);
                    	}
                    	return 0;
                    }    
