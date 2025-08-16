#include<bits/stdc++.h>
using namespace std;


class DSU{
    public:
    vi parent;

    DSU(int V){
        parent.resize(V,-1);
    }

    int findParent(int node){
        if(parent[node] < 0) return node;
        return parent[node] = findParent(parent[node]);
    }

    void insert(int u, int v){
        int paru = findParent(u), parv = findParent(v);
        
        if(paru == parv) return;

        if(parent[paru] <= parent[parv]){
            parent[paru] += parent[parv];
            parent[parv] = paru; 
        } else {
            parent[parv] += parent[paru];
            parent[paru] = parv; 
        }
    }

    int SCC(){
        int cnt =0;
        for(int rank:parent){
            if(rank < 0) cnt++;
        }
        return cnt;
    }
};


int main(){

    return 0;
}
