#include<bits/stdc++.h>
using namespace std;


  int numberOfDistinctSubseq(string& str){
        unordered_map<char,int> subsequencesBeforeLastOccurence;
        int count = 1, newCount;
        
        
        for(auto ch:str){
            
             newCount = 2 * count;
            
            if(subsequencesBeforeLastOccurence.find(ch) != subsequencesBeforeLastOccurence.end()){
                newCount -= subsequencesBeforeLastOccurence[ch];
            }
            
            subsequencesBeforeLastOccurence[ch] = count;
            count = newCount;
        }
        
        return count;
  }
    
    string betterString(string str1, string str2) {
        
        if(str1.length() < str2.length()){
            return str2;
        }
        
        if(str2.length() < str1.length() || str1 == str2){
            return str1;
        }
        
        int distinctSubseqFirst = numberOfDistinctSubseq(str1);
        int distinctSubseqSecond = numberOfDistinctSubseq(str2);
        
        if(distinctSubseqSecond > distinctSubseqFirst){
            return str2;
        }
        
        return str1;
    }

int main()
{
        // string str1 = "ljmomlmti";
        // string str2 = "sqapzwbb";

        string str1 = "saa";
        string str2 = "abcbd";

    cout << "Better string: " << betterString(str1, str2) << endl;
    cout << endl;
    return 0;
}