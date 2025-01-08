#include<bits/stdc++.h>
using namespace std;

/*

    Main principle :-> If indegree of a node is not becoming zero while traversing from the least dependent node then it means that they are connected to something which is not a independent in itself and this will happen when you are somehow connected to yourself or you are part of a cycle

    Beauty of Topological sort:

    It won't include the nodes which is anyhow a part of cycle or connected to itself via a path

 */
 
 bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> inDegree(V);
        
        for(int i = 0; i < V; i++){
            for(int x:adj[i]){
                inDegree[x]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> nodeDontHaveCycles;
        
        while(!q.empty()){
            nodeDontHaveCycles.push_back(q.front());
            
            for(int x:adj[q.front()]){
                inDegree[x]--;
                if(inDegree[x] == 0) q.push(x);
            }
            
            q.pop();
        }
        
        return (nodeDontHaveCycles.size() != V); // If the topologically sorted array contains all the vertex means there is no cycle in the graph but if there is a cycle then topologically sorted array never contains the related nodes which particlipate in that cycle
        
    }

int main(){
    
 cout << endl;
return 0;
}