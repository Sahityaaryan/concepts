#include<bits/stdc++.h>
using namespace std;

/**
 * * Binary exponentiation
 * 
*/

 double myPow(double x, int n) {
       
       double ans = 1.0;

        long long nn = (static_cast<long long>(n));

        if(n < 0){
            nn = -1*nn;
        }

       while(nn){

            if(nn%2){
                ans *= x;
                nn--;
                cout << "\nx: " << x  << "\tnn: " << nn << endl;
            } 
                x *= x;
                nn/=2;
       }

        return (n < 0) ? 1/ans : ans;
    }


int main()
{
    cout << myPow(2,7);
    cout << endl;
    return 0;
}