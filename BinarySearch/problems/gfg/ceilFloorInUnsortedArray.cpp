#include<bits/stdc++.h>
using namespace std;

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int f=-1,c=1e9,n=arr.size();
        
        for(int i=0 ; i<n ; i++){
            if(arr[i]<=x)f=max(f,arr[i]);
            if(arr[i]>=x)c=min(c,arr[i]);
        }
        
        if(c==1e9)return {f,-1};
        return {f,c};
    }

int main()
{
 
    
    cout << endl;
    return 0;
}