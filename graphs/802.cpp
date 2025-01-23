#include<bits/stdc++.h>
using namespace std;
 

/*
    first_learning: From this very Problems I got the idea that the bfs can be used to detect cycle
    second_learning: but it also proves one more approach if you want something that must goes from the end or leaf nodes then why not to start traversing the leaf nodes or end.
    
*/



vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    // reverse the direction of the graph so now the terminal nodes will become the origin or less dependent nodes of the 
    // graph

    // Here we just have to see which nodes are dependent on the terminal nodes (which are now the less dependent nodes) without having any kind of loop

    // And as the nature of detecting cycle using BFS it won't count or visit those nodes which has cycles so we will be automatically getting only those nodes whose all the paths are only with the initial dependent nodes or the origin nodes.
    
     int n = graph.size();
    vector<vector<int>> rev(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        indegree[i] = graph[i].size(); // here we are calculating the indegree as outdegree because on reversing the graph the outdegree becomes the indegree
        for (auto it : graph[i]) {
            rev[it].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for (auto it : rev[top]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


int main(){
    
 cout << endl;
return 0;
}