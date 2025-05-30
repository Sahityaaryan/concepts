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


    Problem with stack is that I have to run the loop twice if i didn't find any loop with the visited node and extra space as well

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



// 2. This is that everywhere available approach but I optimized it space wise

/*

    bool dfs(vector<vector<int>>& adj, int v, vector<int>& visitCount){
        
        visitCount[v] = 2; // here I am giving it 2 because ((I am visiting this node) +
        // (and this node is part of the path I am currently following))
    
        for(int x:adj[v]){
            
            if(visitCount[x]) {
              if(visitCount[x] == 2) return true;
              
            } else if(dfs(adj, x, visitCount)) return true;
        }
        
        visitCount[v] = 1; // (now it is 1 because it siginifies that I have only visited this node
        // but it is not a part of the current path I am following)
        return false;
    }
    
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> visitCount(adj.size());
        
        for(int i = 0; i < adj.size(); i++){
            if(!visitCount[i]){
                if(dfs(adj, i, visitCount)){
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