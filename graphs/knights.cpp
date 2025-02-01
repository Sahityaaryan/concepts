#include<bits/stdc++.h>
using namespace std;
 
  /*
        Learning :->
        
        1. If you have to call too many dfs like more than 4 then don't use dfs because it will tak a 
        take a huge space in the recursion stack go for the dfs
        
        2. Especially in the questions of moving to 4 or 5 positions at a time, in both bfs and dfs 
        you should make sure that a position which is already calculated should not be calculated
        again (use something similar to isVisited)
        
        3. second optimization of time I was previously checking the right position when I have 
        already entered the a lot of combination so if just return the answer while entering the 
        position it will same me a lot of space and time
    */

  	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
	{
	   if(kp == tp) return 0;
	   
    vector<vector<int>> directions = {{-2,1}, {-2,-1}, {2,1}, {2,-1}, {1,-2}, {-1,-2},{1,2}, {-1,2}};
	   
	    vector<vector<int>>isVisited(N+1, vector<int>(N+1,0));
	   
	    queue<pair<int, int>> q;
	    int steps = 0;
	    isVisited[kp[0]][kp[1]] = 1;
	    q.push({kp[0], kp[1]});
	    
	    while(!q.empty()){
	        
	        int n = q.size();
	        
	        while(n--){
	            
    	        int u = q.front().first;
    	        int v = q.front().second;
    	    
    	        q.pop();
	            
	        for(auto dir:directions){
	            int newu = u + dir[0];
	            int newv = v + dir[1];
	            if(newu == tp[0] && newv == tp[1]) return steps+1;
	            
	            if(newu > 0 && newu <= N && newv > 0 && newv <= N && isVisited[newu][newv]==0){
                    isVisited[newu][newv] = 1;
	                q.push({newu, newv});    
	            }
	          }
	        }
	        steps++;
	    }
	    
	    return -1;
	}


int main(){
    
 cout << endl;
return 0;
}