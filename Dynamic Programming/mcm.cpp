//mcm
//Build partition tree first.
//Implement using modified mcm.
#include<bits/stdc++.h>

int getMax(vector<int> &arr,int start,int end){
    
    int mx = 0;
    for(int i=start;i<=end;i++){
        mx = max(mx,arr[i]);
    }
    
    return mx;
    
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    
    int n = arr.size();
    
    int C[n];
    
    for(int i=0;i<n;i++){
        
        int mx = 0;
        
        for(int j=0;j<i;j++){
            
            if(i-j <= k)
                mx = max(mx , C[j] + getMax(arr,j+1,i)*(i-j));
            
        }
        
        if(i+1 <= k)
            C[i] = max(mx , getMax(arr,0,i)*(i+1));
        else
            C[i] = mx;

    }
    
    return C[n-1];
    
    
}