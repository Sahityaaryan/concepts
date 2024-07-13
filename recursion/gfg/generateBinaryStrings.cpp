#include<bits/stdc++.h>
using namespace std;

void genBinary(int n,vector<string>& binaryStringArray, char firstChar, string s){

 if(firstChar != ' '){

    s += firstChar;

       if(!n){
        binaryStringArray.push_back(s);
        return;
    }


    if(firstChar - '0' == 1){
        genBinary(n-1,binaryStringArray,'0',s);
    } else {
        genBinary(n-1,binaryStringArray,'0',s);
        genBinary(n-1,binaryStringArray,'1',s);
    }
 } else {
    genBinary(n-1,binaryStringArray,'0',s);
    genBinary(n-1,binaryStringArray,'1',s);
 }
}

int main()
{
    vector<string> binaryStringArray;
    genBinary(5, binaryStringArray, ' ', "");

    // cout << "\nBinary:\t";

    // for(auto it: binaryStringArray){
    //     cout << it << "\n";
    // }


    cout<< "size: " << binaryStringArray.size();

    // T.C  <  O(2N-1) || O(N)
    // S.C : O(1)


    cout << endl;
    return 0;
}