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

        // here first_rightmost_different_bit is actually an even number like "1000" where the positon of set bit represent the first rightmost different bit
        // as till the rightmost '1' all the '0' are representing similar bits of both the numbers so by this info different of the bit at the 4th place from
        // right we head to find the xor of number which has a set bit at the 4th place and the unset bit at the 4th place 
        
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