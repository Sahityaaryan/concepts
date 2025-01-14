#include<bits/stdc++.h>
using namespace std;
 

  int spanningTree(int V, vector<vector<int>> adj[]) {
       
       int mst_val = 0;
       int min_key = -1;
       bool found_min = true;
       
       vector<int> key(V, INT_MAX);
       vector<bool> mst(V);
       
       key[0] = 0;
       
       while(found_min){
           found_min = false;
           min_key = -1;
          int min_val = INT_MAX;
           
           for(int i = 0; i < V; i++){
               if(key[i] < min_val && !mst[i]){
                   min_key = i;
                   min_val = key[i];
                   found_min = true;
               }
           }
           
           if(found_min) mst_val += key[min_key];
           else break;
           
        //   marking the nodes in the mst
        
        mst[min_key] = true;
           
        //   finding adjacent nodes
        
            for(auto nodes:adj[min_key]){
                int v = nodes[0];
                int weight = nodes[1];
                
                if(key[v] > weight) key[v] = weight;
            }
       }
       
       return mst_val;
       
    }

int main(){
    
 cout << endl;
return 0;
}