#include<bits/stdc++.h>
using namespace std;

int calculateNoOfSubstring(int lead,int lag){
    int n = lead-lag+1;
    return (n*(n+1))/2;
}

long long int calcCount2(string s,int k){
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
        if(dist_count==k){
            ans += calculateNoOfSubstring(leader,lagger);
        }
            while(dist_count>k){
                charFreq[s[lagger]-'a']--;
                if(charFreq[s[lagger]-'a']==0){
                    dist_count--;
                }
                lagger++;
            }


            // ans+=(leader-lagger+1); // * here I don't know but summing up window size it is providing correct number of substrings whose distinct chars are less than or equal to "k".
            leader++;
        }
        return ans ;
}


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


            ans+=(leader-lagger+1); // * here I don't know but summing up window size it is providing correct number of substrings whose distinct chars are less than or equal to "k".
            leader++;
        }
        return ans ;
}



 long long int substrCount(string s, int k ){
    // long long int numberOfKunique = calcCount2(s,k);
    // long long int numberOfKunique2 = calcCount2(s,k-1);

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


    cout << "\nAnswer: " << substrCount(s,k);

    // s = "aacaebceaac";
    // k = 4;
    // cout << "ans: " << subStrCount3(s,k);
    // cout << "ans: " << substrCount(s,k);


    cout << endl;
    return 0;
}