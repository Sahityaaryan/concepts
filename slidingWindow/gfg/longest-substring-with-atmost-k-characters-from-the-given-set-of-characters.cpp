#include<bits/stdc++.h>
using namespace std;



// Questions: https://www.geeksforgeeks.org/longest-substring-with-atmost-k-characters-from-the-given-set-of-characters/

int maxNormalSubstring(string& P, set<char> Q, int K, int N) {

   int mp[265];

   fill(mp, mp+265, 0);

    set<char>::iterator it;

    for(auto it = Q.begin(); it != Q.end(); it++){
        mp[*it]++;
    }


    int window = 0, lead = 0, lag = 0;

    while(lead < P.length()){
        if(mp[P[lead]]){
            K--;
        }

        while(K < 0){
            if(mp[P[lag]]){
                K++;
            }
            lag++;
        }

        window = max(window, lead-lag+1);
        lead++;
    }

    return window;
}
 
int main() 
{ 
    // string P = "giraffe"; 
     string P = "normal"; 
    set<char> Q; 
     
    // Construction of set 
    Q.insert('a'); 
    Q.insert('o'); 
    Q.insert('n'); 
    Q.insert('m'); 
    Q.insert('r'); 
    Q.insert('l'); 
    int K = 1; 
    int N = P.length(); 
 
    // output result 
    cout << maxNormalSubstring(P, Q, K, N); 

 
    return 0; 
} 


int func(string s, int k){
    int maxLen = 0, l = 0, r = 0;
    unordered_map<char, int> mp;

    while(r < s.length()){
        mp[s[r]]++;

        if(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }

        if(mp.size() <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
}


// T.C : O(N) + O(log(256))
// S.C : O(256)