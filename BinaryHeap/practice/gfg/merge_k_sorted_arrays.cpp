#include<bits/stdc++.h>
using namespace std;



vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int pointer[K];
        fill(pointer, pointer+K, 0);
        
        vector<int> vec(K*K, 0);
        
        int i = 0;
        
        while(i < K*K){
            int p = 0;
            int previousPointer = -1;
            int smallest = INT_MAX;
            
            while(p < K){
                if(pointer[p] < K && arr[p][pointer[p]] < smallest){
                    smallest = arr[p][pointer[p]];
                    if(previousPointer >= 0){
                    pointer[previousPointer]--;
                    previousPointer = p;
                    }
                    
                    previousPointer = p;
                    
                    pointer[p]++;
                }
                p++;
            }
                vec[i] = smallest;
            i++;
        }
        
        return vec;
       
       
    }
 
int main(){
    
 cout << endl;
return 0;
}