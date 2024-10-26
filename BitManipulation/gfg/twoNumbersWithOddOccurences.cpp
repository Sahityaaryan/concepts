#include<bits/stdc++.h>
using namespace std;
 
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xor_res = 0;
        
        for(long long int i = 0;i < N; i++){
            xor_res ^= Arr[i];
        }
        
        long long int res1 = 0;
        long long int res2 = 0;
        
        int first_rightmost_different_bit = xor_res & ~(xor_res-1);
        
        for(long long int i = 0;i < N; i++){
            if(Arr[i] & first_rightmost_different_bit){
                res1 ^= Arr[i];
            } else {
                res2 ^= Arr[i];
            }
        }
        
        if(res1 > res2) return {res1, res2};
        
        return {res2, res1};
    }


int main(){
    
 cout << endl;
return 0;
}