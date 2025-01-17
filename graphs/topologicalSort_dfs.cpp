#include<bits/stdc++.h>
using namespace std;

/*

Basic Pirnciple of the topological sort --> the parent nodes should be written before the child node or all the nodes which are 
before the current node in any connection should be written before the current node (any connection means there may be more than
one path that leads to the current node) 

 so here in this approach :-> we are storing the last number of the traversal at the end which is logically correct like while
 traversing through dfs if a node comes after a number of nodes then the current nodes is clearly dependent over the previous 
 number of nodes. 

 so in this algorithm what are we doing is we are traversing like normal DFS but at the end when the function propagates backwards
 after reaching the final element of the relation we store it in the stack and hence ensuring that the highly dependent nodes 
 or the last nodes of the relation should be at the bottom of the stack while the initial ones from where the recursion or relationship
 started remains on the top of the stack.

 */
 
     void dfsrec(vector<vector<int>>& adj, int v, vector<bool>& isVisited, stack<int>& st){
        
        isVisited[v] = true;
        
        for(int x:adj[v]){
            if(!isVisited[x]){
                dfsrec(adj, x, isVisited, st);
            }
        }
        
        st.push(v);
    }
    
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // You
        
        vector<int> topologicallySortedNodes;
        
        stack<int> st;
        vector<bool> isVisited(adj.size()+1,false);
        
        for(int i = 0; i < adj.size(); i++){
            if(!isVisited[i]){
                dfsrec(adj, i, isVisited, st);
            }
        }
        
        
        // extracting the elements
        
        while(!st.empty()){
            topologicallySortedNodes.push_back(st.top());
            st.pop();
        }
        
        
        return topologicallySortedNodes;
    }


int main(){
    
 cout << endl;
return 0;
}