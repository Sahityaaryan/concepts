#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<int> adj[], int src, vector<bool> &isVisited)
{
    
      queue<int> q;

      q.push(src);
      isVisited[src] = true;

      int i = 0,j = 0;

     while(!q.empty())
     {
        i = q.front();
        q.pop();
        
        cout << " " << i;
        j = 0;

        while(j < adj[i].size())
        {
            if (!isVisited[adj[i][j]])
            {
                q.push(adj[i][j]);
                isVisited[adj[i][j]] = true;
            }
            j++;
        }
     }
 }

 void discreteBFS(vector<int> adj[], int v)
 {
     vector<bool> isVisited(v + 1, false);

     int i = 0;

     while (i < v)
     {
         if (!isVisited[i])
         {
             bfs(adj, i, isVisited);
         }
         i++;
     }
 }

     void addEdge(vector<int> adj[], int u, int v)
 {

     adj[v].push_back(u); // as it is a undirected graph
     adj[u].push_back(v);
    //  cout << "adding\n";
    
}

void printArr(vector<int> adj[])
{


    for(int i = 0;i <4;i++)
    {
        // cout << "i";
            for (auto j: adj[i] )
            {
                cout << " " << j <<' ';
            }
            cout <<'\n';
    }
}





int main(){



    //array of vectors
    vector<int> v[6];

// cout << "jai mata di";
    addEdge(v,0,5);

    addEdge(v,0,4);

    addEdge(v,4,3);
    addEdge(v,5,3);

    //discontinours grapkh
    addEdge(v,2,1);
    addEdge(v,2,6);
    addEdge(v,1,6);

    // cout << "my graph";

    // for(auto i : v[0])
    // {
    //     cout << " " << i++;
    // }

    // cout << "end\n";

    discreteBFS(v,6);
    

        return 0;
}