#include<bits/stdc++.h>
using namespace std;

#define d double

/**
 * * Binary exponentiation
 * 
*/

      d myPow(double x, int n) {

        if(x == 1 || n==1){
            return x;
        }
    
    d res = x;
    d ans = 1;

    long long nn = static_cast<long long>(n); // There is a need of converting it to long long because we are converting it to +ve and 
    // -2147483648 => 2147483648 and this is out of the range for an Integer

    nn = abs(nn);
    
    while(nn){

        if(nn%2){
            ans = ans * res;
            nn--;
        } 

            res = res * res;
            nn /= 2;
        
    }

    return n < 0 ? 1/ans:ans;
    }


int main()
{
    cout << myPow(2,7);
    cout << endl;
    return 0;
}