#include <bits/stdc++.h>
using namespace std;


void bitManipulation(int num, int i) {
        // your code here
        i--;
        cout << ((num & (1 << i) )!= 0) << " " << (num | (1 << i)) << " " << (num & ~(1 << i));
    }

int main()
{
    int i = 3;
    int num = 70;
    cout << endl;
    return 0;
}