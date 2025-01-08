#include<bits/stdc++.h>
using namespace std;

/*
    This approach is mostly choosing the node which is having the less indegree first so here we have implemeted the queue which is like
    the less indegree or the less dependent nodes will remain at the top of it.

    first we will calculate the indegree of every node too have an idea that from how many paths we can reach to that node. 
    
    Then we will start by all those nodes whose indegree are 0 we simply push them in the queue because these are the universal
    parent node  means every path in the graph is originated from these nodes only so if we dig out the root these parent nodes
    we will surely get all the nodes

    while traversing to all the nodes we wil reduce the indegree here we actually reducing the path of that node to which it is
    connected once a node's indegree becomes zero it means now it is not the part of any path and it will now act as the universal
    parent for the rest of node which are connected to the path lead by it. and so we will push the new universal parent node
    into the queue
    
*/


 
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        vector<int> indegree(adj.size(),0);
        vector<int> topologicalSortedNodes;
        
        for(auto v:adj){
            for(int x:v){
                indegree[x]++;
            }
        }
        
        queue<int>q;
        
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            topologicalSortedNodes.push_back(q.front());
            
            for(int x:adj[q.front()]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
            
            q.pop();
        }
        
        return topologicalSortedNodes;
    }

int main(){
    
 cout << endl;
return 0;
}