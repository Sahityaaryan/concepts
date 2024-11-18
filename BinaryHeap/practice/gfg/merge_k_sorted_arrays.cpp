#include<bits/stdc++.h>
using namespace std;



vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int pointer[K];
        fill(pointer, pointer+K, 0);
        
        vector<int> vec(K*K, 0);
        
        int i = 0;
        
        while(i < K*K){
            int p = 0;
            int previousPointer = -1;
            int smallest = INT_MAX;
            
            while(p < K){
                if(pointer[p] < K && arr[p][pointer[p]] < smallest){
                    smallest = arr[p][pointer[p]];
                    if(previousPointer >= 0){
                    pointer[previousPointer]--;
                    previousPointer = p;
                    }
                    
                    previousPointer = p;
                    
                    pointer[p]++;
                }
                p++;
            }
                vec[i] = smallest;
            i++;
        }
        
        return vec;
       
       
    }


// using heap


    class data{
        public:
        int val, apos, vpos;
        data(int v, int ap, int vp){
            val = v;
            apos = ap;
            vpos = vp;
        }
    };

    struct mycomp{
        bool operator()(data &d1, data &d2){
            return d1.val > d2.val;
        }
    };

    class Solution
    {
        public:

        vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<data, vector<data>, mycomp> mh;
        
        vector<int> vec;
        
        int p = 0;
        
        while(p < K){
            data d(arr[p][0], p,0);
            mh.push(d);
            p++;
        }
        
        while(!mh.empty()){
            data d1 = mh.top();
            mh.pop();
            vec.emplace_back(d1.val);
            int ap = d1.apos, vp = d1.vpos;
            
            if(vp+1 < arr[ap].size()){
                // data* newD = new data(arr[d1->pos][d1->pointer], d1->pos, d1->pointer);
                data d(arr[ap][vp+1], ap, vp+1);
                mh.push(d);
            }
        }
        
        return vec;
        
       
    }
 

int main(){
    
 cout << endl;
return 0;
}