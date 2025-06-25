#include<bits/stdc++.h>
using namespace std;
 




/*
    1. using the loop approach

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
           
        //   finding adjacent nodes and updating the key vector 
        
            for(auto nodes:adj[min_key]){
                int v = nodes[0];
                int weight = nodes[1];
                
                if(key[v] > weight) key[v] = weight;
            }
       }
       
       return mst_val;
       
    }

    // T.C : O(V*(V + V)) = O(V^2 + V^2)
    // S.C : O(2V)



    2. using priority_queue for little optimization at time

        int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // prim's algorithm
       
       int mst_val = 0;
       int min_key = -1;
       int number_of_nodes_connected = 0;
       bool found_min = true;
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> key;
       
       vector<int> mst(V, false);
   
        
       key.push({0, 0});
        
       
       while(!key.empty()){
           found_min = false;
           
           while(mst[key.top().second]){
               key.pop();
           }
           
           if(key.empty()) break;
           
           min_key = key.top().second;
           mst[min_key] = true;
           mst_val += key.top().first;
           number_of_nodes_connected++;
           
           key.pop();
           
        //   finding adjacent nodes
        
            for(auto nodes:adj[min_key]){
                int v = nodes[0];
                int weight = nodes[1];
                
               if(!mst[v]) key.push({weight, v});
            }
            
            if(number_of_nodes_connected == V) break;
       }
       
       return mst_val;
       
       
    //   T.C : O(V*(V + logV)) = O(V^2 + V*logV)
    // S.C : O(2V)

    */

int main(){
    
 cout << endl;
return 0;
}