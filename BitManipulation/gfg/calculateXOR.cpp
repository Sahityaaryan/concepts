#include<bits/stdc++.h>
using namespace std;

int findXOR(int l, int r) {
     
     int cnt = 0;
     
     while(r >= (1 << cnt)){
         cnt++;
     }
     cnt--;
     
     int nextNum = ((1 << cnt) > l) ? (1 << cnt) : l;
     int ans = 0;
     
     while(nextNum <= r){
         ans ^= nextNum;
         nextNum++;
     }
     
     return ans;
    }

int main()
{
    int l = 2226, r = 6797;
    // 2226 6797
    cout << "XOR: " << findXOR(l,r);
    cout << endl;
    return 0;
}