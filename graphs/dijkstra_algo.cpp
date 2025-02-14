#include<bits/stdc++.h>
using namespace std;
 
  
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        
        pq.push({0,src});
        distance[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto x:adj[node]){
                int adj_node = x.first;
                int weight = x.second;

                if(dist +weight <  distance[adj_node]){
                    distance[adj_node] = dist + weight;
                    pq.push({dist+weight, adj_node});
                }
            }
        }

        return distance;
    }


int main(){
    
 cout << endl;
return 0;
}