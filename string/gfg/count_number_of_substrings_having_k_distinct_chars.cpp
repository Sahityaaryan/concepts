#include<bits/stdc++.h>
using namespace std;

int numberOfDistinctChars(string s){ // it is not seeming more efficient than the map but still map is a graph so may it take time to 
// implement a graph but implementing an array won't take time but yes it will take some fixed space
    char arr[26];

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