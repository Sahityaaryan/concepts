#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &in){

     // here the stack's nextgreater won't work, you have to traverse

     // Here the crux is that you inorder to save the T.C you have to traverse the entire array only for the given
     // index postions


    vector<int> ans(q,0);
    for(int i = 0;i<q;i++){
        int j = n-1;
        while(in[i]<j){
            if(arr[j]>arr[in[i]]) ans[i]++;
            j--;
        }
    }
    return ans;

 }

int main(){

    cout << endl;

    return 0;
}
