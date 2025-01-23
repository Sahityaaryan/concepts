#include<bits/stdc++.h>
using namespace std;
 
// 207. Course Schedule-> wonderfull question which needs to detect cycle from a directed graph and how one should thinks of graph data structure for real life problems

    unordered_map<int, vector<int>> createAdjacencyList(vector<vector<int>>& prerequisites, int numCourses){
            unordered_map<int, vector<int>> adj(numCourses+1);

            for(auto pre:prerequisites){
                adj[pre[1]].push_back(pre[0]); 
            }

            return adj;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //  this is clearly a graph question where we have to detect cycles in a directed graph
        // which is more easy than the undirected graph

        
        vector<int> indegree(numCourses);

        unordered_map<int, vector<int>> adj = createAdjacencyList(prerequisites, numCourses);
        
        // solving it via topolocial sort #BFS 

        unordered_map<int, vector<int>>::iterator it = adj.begin();

        while(it != adj.end()){
            for(int x:it->second) indegree[x]++;
            it++;
        }

        queue<int> q;

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        int nodes_counter = 0;

        while(!q.empty()){
            nodes_counter++;
            for(int x:adj[q.front()]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
            q.pop();
        }

        return nodes_counter == numCourses;

        
    }


int main(){
    
 cout << endl;
return 0;
}