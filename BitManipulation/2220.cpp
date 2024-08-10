#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
        int num = start ^ goal;

        int minBitToFlip = 0;

        while(num){
            num = num & (num-1);
            minBitToFlip++;
        }

        return minBitToFlip;
    }

int main()
{
 
    
    cout << endl;
    return 0;
}