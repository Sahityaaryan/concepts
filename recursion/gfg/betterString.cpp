#include<bits/stdc++.h>
using namespace std;


int calculatingSubseq(string str, string parent, int ind,  unordered_map<string,int>& mp){
    
    if(ind == parent.length()){
        
        if(!mp[str]){
            mp[str]++;
            return 1;
        }
        
        return 0;
    }
    
    int take = calculatingSubseq(str + parent[ind], parent, ind + 1, mp);
    int notTake = calculatingSubseq(str , parent, ind + 1, mp);
    
    return take + notTake;
}

string betterString(string str1, string str2) {
    
    if(str1.length() < str2.length()){
        return str2;
    }
    
    if(str2.length() < str1.length() || str1 == str2){
        return str1;
    }
    
    unordered_map<string,int> mp1;
    unordered_map<string,int> mp2;
    
    
    int distinctSubseqFirst = calculatingSubseq("", str1, 0, mp1);
    int distinctSubseqSecond = calculatingSubseq("", str2, 0, mp2);

    cout << "first " << distinctSubseqFirst << " second " << distinctSubseqSecond<< endl;

    
    if(distinctSubseqSecond > distinctSubseqFirst){
        return str2;
    }
    
    return str1;
}

int main()
{
        // string str1 = "ljmolmti";
        // string str2 = "sqapzwbb";

        string str1 = "abcdee";
        string str2 = "abcbd";

    cout << "Better string: " << betterString(str1, str2) << endl;
    cout << endl;
    return 0;
}