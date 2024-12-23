#include<bits/stdc++.h>
using namespace std;

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {


      vector<pair<int , int>> vp(id.size());
       int ut = 0, pg = 0;
       int max_deadline = 0;

       for(int i = 0;i < id.size(); i++){
           vp[i] = {deadline[i], profit[i]};
           max_deadline = max(max_deadline, deadline[i]);
       }

       sort(vp.begin(), vp.end(), [](const pair<int , int>& a,const pair<int , int>& b )->bool{
           return a.second > b.second;
       });

       vector<int> jobs(max_deadline + 1, -1);

       for(int i  = 0; i < vp.size(); i++){
           int j = vp[i].first;
           while(jobs[j] != -1 && j){
               j--;
           }

           if(j > 0){
               jobs[j] = i;
               ut++;
               pg += vp[i].second;
           }
       }


       return {ut, pg};
   }

int main(){


    return 0;
}
