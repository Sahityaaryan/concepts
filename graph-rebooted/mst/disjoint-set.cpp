#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define ll long long
#define F first
#define S second
#define ln(s) ((int)(s).length())
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define sst stringstream
#define vb vector<bool>
#define ima INT_MAX
#define imi INT_MIN

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

        if(parent[paru] < parent[parv]){
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
