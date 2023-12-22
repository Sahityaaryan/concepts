#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

 void bfs(vector<int> adj[],int src,int v)
 {
    vector<bool>isVisited (v+1,false);
      
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


void addEdge(vector<int> adj[],int u,int v)
{
  
    adj[v].push_back(u); //as it is a undirected graph
    adj[u].push_back(v);
    
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



    //aray of vectors
    vector<int> v[5];

    addEdge(v,0,1);

    addEdge(v,0,2);
    addEdge(v,1,2);

    addEdge(v,1,3);
    addEdge(v,2,3);
    addEdge(v,3,4);
    addEdge(v,2,4);


    bfs(v,0,4);


    // p(arr);

    // cout << arr[1];

    // printArr(v);

        return 0;
}