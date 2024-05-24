#include<bits/stdc++.h>
using namespace std;

// new method of checking whether it is isomorphic string or not

void normalise(string &s){
    unordered_map<char,char>mp;
    char tipAlphabet = 'a';

    for(char ch:s){
        if(!mp[ch]){
            mp[ch] = tipAlphabet;
            tipAlphabet++;
        }
    }
    int i = 0;

    while(i < s.length()){
        s[i] = mp[s[i]];
        i++;
    }
}

bool isoMorphic

   bool isIsomorphic(string s, string t) {
        
        // first check: size must be same

        if(s.size() != t.size()) return false;

// second check : we will actually check the mapping of the function

        unordered_map<char,char>mp1,mp2;

        int i = 0;

        

        while(i < s.size()){
            
            if((int)mp1[s[i]] == 0){
                if((int)mp2[t[i]] == 0){
                    mp1[s[i]] = t[i];
                    mp2[t[i]] = s[i];
                } else {
                    return false;
                }
            }

            if(mp1[s[i]] != t[i]){
                return false;
            }
            i++;
        }

        return true;
       
    }

int main()
{
    string s2,s1;

    s1 = "add";
    s2 = "egg";
    normalise(s2);
    normalise(s1);

    cout << "after normalisation " << s1<< endl;
    cout << "before normalisation " <<  s2 << endl;



    cout << endl;
    return 0;
}