#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1971. Find if Path Exists in Graph


bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{

    unordered_map<int, vector<int>> mp;
    for (auto i : edges)
    {
        vector<int> temp = i;
        int u = temp[0];
        int v = temp[1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : mp[u])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return visited[destination];

}

int main()
{

    cout << endl;
    return 0;
}