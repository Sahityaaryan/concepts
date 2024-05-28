#include<bits/stdc++.h>
using namespace std;

int countUniqueElements(string s){
    vector<int> v(26,0);
    // fill(v,v+s.len)
    int i = 0,numberOfUniqueElements = 0;

    while(i < s.length()){
        if(!(v[s[i]-'a'])){
            v[s[i]-'a']++;
            numberOfUniqueElements++;
        }
        i++;
    }

    return numberOfUniqueElements;
}

void  generateSubString(string s, int charCount, vector<string> &ans){
    if(charCount == s.length()+1){
        return;
    }

    int i = 0;

    while(i < s.length()-charCount + 1){
        string temp = s.substr(i,charCount);
        ans.push_back(temp);
        i++;
    }

    return generateSubString(s,charCount+1,ans);
}


void generateStrings(string str, int start, vector<string>& result) {
    if (start == str.length()) {
        result.push_back(str);
        return;
    }

    for (int i = start; i < str.length(); i++) {
        swap(str[start], str[i]);
        generateStrings(str, start + 1, result);
        swap(str[start], str[i]); // backtrack
    }
}


int subStrCount2(string s,int k){
   int leader = 0,lagger = 0,count = 0;
    unordered_map<char,int> mp;
    int numberOfUnqiueElements = 0;

    fill(arr,arr+26,0);

    int i = 0,count = 0;

    while(i < s.length()){
        if(!arr[s[i]-'a']){
            count++;
        }
        arr[s[i++]-'a']++;
    }

    return count;
}

vector<string> substrings(string s,int k){ // not a substring


    vector<string> ans;

    int start = 0, end = 1,i = 0,count=0;
    string subString;

    while(end < s.length()){
        subString = s.substr(start,end-start+1);
        count = numberOfDistinctChars(subString);    

        if(!(count-k)){
            ans.push_back(subString);
        } 
        end++;   
    }

    while(start < end-1){
        subString = s.substr(start,end-start+1);
        count = numberOfDistinctChars(subString);    

        if(!(count-k)){
            ans.push_back(subString);
        } 
        start++;   
    }

    return ans;
}

int main()
{

    string str = "sanu";
    int k = 2;



    cout << endl;
    return 0;
}