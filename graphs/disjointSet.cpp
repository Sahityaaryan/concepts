#include<bits/stdc++.h>
using namespace std;
 

class DisjointSet{

    vector<int> rank,parent,size;

    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);

            for(int i = 0; i < parent.size(); i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int pu = parent[u];
            int pv = parent[v];

            if(pu == pv) return; // must case to see when they are already united

            int ranku = rank[pu];
            int rankv = rank[pv];

            if(ranku == rankv){
                parent[pv] = pu;
                rank[pu]++;
            } else if(ranku > rankv){
                parent[pv] = pu;
            } else {
                parent[pu] = pv;
            }
        }

        void unionBySize(int u, int v){
            int pu = parent[u];
            int pv = parent[v];

            if(pu == pv) return; // must case to see when they are already united

            int sizeu = size[u];
            int sizev = size[v];

            if(sizeu >= sizev){
                size[pu] += size[pv]; 
                parent[pv] = pu;
            } else {
                size[pv] += size[pu];
                parent[pu] = pv;
            }
        }
};

int main(){

    DisjointSet ds(7);  
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findParent(3) == ds.findParent(7)){
        cout << "same\n";
    } else cout << "not same\n";

    ds.unionBySize(3,7);


    if(ds.findParent(3) == ds.findParent(7)){
        cout << "same\n";
    } else cout << "not same\n";

 cout << endl;
return 0;
}