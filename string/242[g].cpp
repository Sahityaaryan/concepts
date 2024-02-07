#include<bits/stdc++.h>
using namespace std;

// # more optimized way of finding the anagrams

  bool isAnagram(string s, string t) {

        int arr[26];
        fill(arr,arr+26,0);

        if(t.length() != s.length()) return false;

        int i = 0,n = s.size();

        while(i < n){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
            i++;
        }

        i = 0;

        while(i < 26){
            if(arr[i]!=0) return false;
            i++;
        }

        return true;
        
    }
int main()
{
 
    
    cout << endl;
    return 0;
}