#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    
    int a = 27; // 1 1 0 1 1
    int b = 1;// 1

    //1. finding the ith bit

    int targetBit = 3;

    int maskBits = b << (targetBit-1); // 1 0 0

    int answer = a & maskBits;

    if(answer != 0) cout << "the ith bit is 1" ;
    else cout << "the ith bit is 0";


    return 0;
}