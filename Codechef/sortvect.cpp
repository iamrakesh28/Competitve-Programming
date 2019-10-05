//#include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;
int interchange(vector<string> arr1,vector<string> arr2)
{
    for(int i=0;i<arr1.size();++i)
    {
        if(arr1[i]>arr2[i])
            return 1;
        else if(arr1[i]<arr2[i])
            return 0;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> arr[unsorted_i];
    }
   // char *pt=NULL;
    vector<string> pt;
    for(int j=0;j<n-1;++j)
    for(int i=0;i<n-1-j;++i)
    {
        int len1,len2;
        len1=arr[i].size();
        len2=arr[i+1].size();
       if(len1>len2)
       {
           pt=arr[i];
           arr[i]=arr[i+1];
           arr[i+1]=pt;
       }
        else
            if(len1==len2)
            {
                int c=interchange(arr[i],arr[i+1]);
                if(c)
                {
                    pt=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=pt;
                }
                            
            }
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[i][0]<<endl;
    }
    return 0;
}
