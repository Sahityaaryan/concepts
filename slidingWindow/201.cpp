#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{

    // 1. the & operation of both numbers will provide
    // either the number less than the smaller one or equal to
    // it

    while (right > left)
    {
        right &= right - 1;
    }

    return right & left;
}

int main(){
    int left = 5;
    int right = 7;

    cout << "ans: " << rangeBitwiseAnd(left,right);


    cout << endl;
    return 0;
}