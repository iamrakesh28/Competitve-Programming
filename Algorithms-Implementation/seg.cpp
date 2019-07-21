#include <stdio.h>
#include <stdio.h>
#include <math.h>
                     
                    #define MN -1
                    using namespace std;
                     
                   typedef struct Element{
                    	long int index;
                    	  long int val,key;
                    } Element;
                     
             
                     
			void merge(Element *arr, long int l, long int m, long int r)
{
     long int i, j, k;
     long int n1 = m - l + 1;
     long int n2 =  r - m;
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
void mergeSort(Element *arr, long int l, long int r)
{
    if (l < r)
    {
         long int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
                    //long int getMid(long int s, long int e) {  return s + (e -s)/2;  }
                     
                    long int left(long int i,long int k)
                    {
                    	if(i-k > 0)
                    	return i-k;
                    	return 0;
                    }
                    long int right(long int n,long int k,long int i)
                    {
                    	if(i+k < n)
                    	return i+k;
                    	return n-1;
                    }
                     
                      long int maxm(   long int a,   long int b) {  return a>b?a:b;  }
                     
                    void updateValue(Element *arr, Element* st, long int ss, long int se,long int index,   long int value, long int node)
                    {
                        	if (index < ss || index > se) 
                        	    return; 
                        	if(ss == se) 
                        	{   
                            	//arr[index].key = value;
                            	st[node].key = value;
                    	//st[node].index = st[node].index;
                        	}
                        	else 
                    	{
                                long int mid = ss + (se -ss)/2;
                                 
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
                    Element MaxUtil(Element* st, long int ss, long int se, long int l, long int r, long int node)
                    {
                        	if(l <= ss && r >= se)
                            return st[node];
                        	if(se < l || ss > r)
                        	{	
                    		Element node;
                    		node.key = MN;
                            	return node;
                        	}
                        	long int mid = ss + (se -ss)/2;//getMid(ss, se);
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
                    Element getMax(Element* st, long int n, long int l, long int r)
                    {
                        	return MaxUtil(st, 0, n - 1, l, r, 0);
                    }*/
                    Element constructSTUtil(Element *arr, long int ss, long int se, Element *st, long int si)
                    {
                        	if (ss == se)
                        	{
                            	st[si] = arr[ss];
                            	return arr[ss];
                        	}
                        	long int mid = ss + (se -ss)/2;//getMid(ss, se);
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
                    Element *constructST(Element *arr, long int n,long int max_size)
                    { 
                        	Element *st = (Element  *)malloc(sizeof(Element)*max_size); 
                        	constructSTUtil(arr, 0, n-1, st, 0);
                    	return st;
                     }
                      
                      long int smallest(long int n,long int k,Element *element,  long int index,Element *st)
                    {
                    	Element node = MaxUtil(st,0, n-1,left(element[index].index,k), right(n,k,element[index].index),0);
                    	if(node.val != element[index].val || node.index == element[index].index)
                    	return node.key + 1;
                    	return node.key;
                    }
                     
                    bool possible(long int k,long int n,Element *element,   long int s,Element *arr,long int max)
                    {
                    	   //long int sum=0;
			 long int sum=0,num,max_small;
                    	 long int start = 0,i;
                    	arr[element[0].index].key = 1;
                    	Element *st = constructST(arr, n,max);
                    	max_small = 1;
                    	//long int i;
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
						for(long int j=0;j<=i;++j)
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
                     
                    long int solve(long int n,   long int s,Element *element,Element *arr,long int max)
                    {
                    	long int begin=0,end=n,middle,check=0;
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
              /*       inline void scanint(  long int &x)

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
                    	Element element[100005];
                    	Element arr[100005];
                    	while(q--)
                    	{
                    		long int n;
                    		  long int s,x;
                    		scanf("%ld%ld",&n,&s);
                    		for(long int i=0;i<n;++i)
                    		{
                    			//scanint(x);
					scanf("%ld",&x);
                    			element[i].index = i;
                    			arr[i].key = 0;
                    			arr[i].val = element[i].val = x;
                    			arr[i].index = element[i].index;
                    			
                    		}
				mergeSort(element,0,n-1);
                    		//sort(element,element + n,compare);
                    		//arr[element[0].index].key = 1;
                    		 x = (long int)(ceil(log2(n))); 
                        	long int max_size = 2*(long int)pow(2, x) - 1;
                    		long int num = solve(n,s,element,arr,max_size);
                    		printf("%ld\n",num);
                    	}
                    	return 0;
                    }    
