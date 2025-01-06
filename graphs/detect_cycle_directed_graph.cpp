#include<bits/stdc++.h>
using namespace std;
 



/*
    This problem can be solved when you realize that if you a node which is visited before then all you have to traverse back the way
    you have come to the node and find in that didn't you visited the node before in the "back propagation" of the path where you have
    found it currently 

    if yes then that means if anybody start from that node along the same path then he will surely meet the node again

    that exactly what I was doing using stack I am entering every element into a stack and also popping it out when they aren't 
    unable to find any visited node in there path and the program has reached the end of the path. so that all means those node 
    will never form any cycle so I remove them form the stack 

    if i found any visited node then i will simply check the stack which contains all the nodes i encountered while moving through 
    the path if found then return true (I have got the cycle) otherwise i will put all the elements back to the stack 

 */


//  1. this solution is not optimized but it's a proof of original thinking (the later is optimized and you will find it everywhere)


/*
  
    bool dfs(vector<vector<int>>& adj, int v, vector<bool>& isVisited, stack<int>& st){
        
        isVisited[v] = true;
        
        st.push(v);
        
        
        for(int x:adj[v]){
            if(isVisited[x]) {
                
                stack<int> temp;
                
                while(!st.empty() && st.top() != x){
                    temp.push(st.top());
                    st.pop();
                }
                
                if(!st.empty()) return true;
                
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
                
            }
            else if(dfs(adj, x, isVisited,st)) return true;
        }
        
       if(!st.empty()) st.pop();
        
        return false;
    }
    
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        stack<int> st;
        vector<bool> isVisited(adj.size(), false);
        
        for(int i = 0; i < adj.size(); i++){
            if(!isVisited[i]){
                if(dfs(adj, i, isVisited, st)){
                    return true;
                }
            }
        }
        
        return false;
    }



*/


int main(){
    
 cout << endl;
return 0;
}