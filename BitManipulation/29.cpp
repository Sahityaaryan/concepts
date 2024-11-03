#include<bits/stdc++.h>
using namespace std;

    int divide(int dividend, int divisor) {


        // questions: 

        // 1. why are we not checking whether the quotient > INT_MAX we are directly checking the (1 << cnt-1) ?
        // Ans:- because the (1 << cnt-1) is an integer and will overflow at 1 << 31 and will give -(2^31) which will eventually reduce the
        // quotient sum which are we doing and hence quotient won't reach the (quotient > INT_MAX) position even though it should.
        // And the divident will also increase because substracting from a negative value will add ultimately and hence we willl get the wrong
        // quotient


        // 2. Why to check only for (1 << cnt-1 == INT_MIN), why not (1 << cnt-1 <= INT_MIN)?
        // Ans:- because the max value of dividend is 2^31  

        if(dividend == 0 || dividend == 1 && (divisor > 1 || divisor < -1)){
            return 0;
        }

        // quotient is bounded

        int cnt = 0;
        ll quotient = 0;
        bool isNeg = (divisor < 0 && dividend > 0 || dividend < 0 && divisor > 0);

        long long divid = abs(static_cast<long long>(dividend));
        long long divis = abs(static_cast<long long>(divisor));

        if(divid == divis){
            return isNeg ? -1:1;   
        }

        

        while(divid >= divis){
            cnt = 0;

            while(divid >= (divis << cnt)){
                cnt++;
            }

            if((1 << cnt-1) == INT_MIN){
                return isNeg ? INT_MIN:INT_MAX;
            }

            divid -= (divis << cnt-1);
            quotient += (1 << cnt-1);
        }

        return isNeg ? -1*quotient : quotient;
        
    }

int main()
{
    int dividend = 12;
    int divisor = 3;

    cout << "\nresult: " << divide(dividend, divisor);
    cout << endl;
    return 0;
}