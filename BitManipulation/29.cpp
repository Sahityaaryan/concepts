#include<bits/stdc++.h>
using namespace std;

    int divide(int dividend, int divisor) {


        int d = divisor, rem = dividend;
        int ans = 0, i = 0;

        bool negAns = false;

        divisor = abs(divisor);
        dividend = abs(dividend);


        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            negAns = true;
        }

        if(divisor > dividend){
            return (negAns ? -dividend : dividend);
        }

        while(rem > divisor){
            d = divisor;
            i = 1;

            while(dividend > d){
                d = d << 1;
                i*=2;
            }

            if(dividend == d){
                ans = i/2;
                rem = 0;
                break;
            }

            cout << "d: " << d << '\n';

            rem = dividend - (d >> 1);

            // cout << "d: " << i << endl;
            // cout << "d : " 
            dividend = rem;

            ans += (i/2);
        }

        if(negAns){
            ans *= -1;
        }

        return ans;
    }

int main()
{
    int dividend = 12;
    int divisor = 3;

    cout << "\nresult: " << divide(dividend, divisor);
    cout << endl;
    return 0;
}