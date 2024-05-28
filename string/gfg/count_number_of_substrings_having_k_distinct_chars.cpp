#include<bits/stdc++.h>
using namespace std;

long long int calcCount(string s,int k){
          int lagger = 0;
        int leader = 0 ;
        int n = s.length() ; 
        // int[] charFreq = new int[26] ; 
        vector<int> charFreq(26,0);
        int dist_count = 0 ;
        long long int ans = 0 ;
        while(leader<n){
            charFreq[s[leader]-'a']++;
            if(charFreq[s[leader]-'a']==1){ //Distinct Character
                dist_count++;
            }
            
            //Decreasing Window Size 
            while(dist_count>k){
                charFreq[s[lagger]-'a']--;
                if(charFreq[s[lagger]-'a']==0){
                    dist_count--;
                }
                lagger++;
            }
            ans+=(leader-lagger+1) ; 
            leader++;
            cout << "leader-lagger+1: " << leader-lagger+1 << endl;
        }
        return ans ;
}

 long long int substrCount(string s, int k ){
    long long int numberOfKunique = calcCount(s,k);
    long long int numberOfKunique2 = calcCount(s,k-1);
        // long long int numberOfKunique2 = 0;

        // cout << "number of unique k " << numberOfKunique << " unique k-1: " << numberOfKunique2 << endl;
        return numberOfKunique - numberOfKunique2;
}


int main()
{
    string s = "ecbaddce";
    int k = 3;
    s = "aba";
    k = 2;



    // s = "aacaebceaac";
    // k = 4;
    // cout << "ans: " << subStrCount3(s,k);
    cout << "ans: " << substrCount(s,k);

    

    cout << endl;
    return 0;
}