#include<bits/stdc++.h>
using namespace std;

int A = 4, B = 97; // random variables which will help in hashing


    vector<vector<int>> preProcessingArrays(string s){

        // A and B are randomly chosen. 

        // h is an vector whose h[k] = HashValue( prefix s[0...k])
        // p is a vector whose p[k] = A^k mod B
        vector<int> p(s.length()) , h(s.length());

        // h[0] = s[0]
        // h[k] = (h[k-1]A + (int)s[k] ) % B


        int i = 1;

        h[0] = s[0];

        while(i < s.length()){
            h[i] = (h[i-1]*A +(int)s[i]) % B;
            i++;
        }

        // p[0] = 1
        // p[k] = (p[k-1]*A) % B

        i = 1;
        p[0] = 1;

        while(i < s.length()){
            p[i] = (p[i-1]*A) % B;
            i++;
        }

    return {h,p};

    }


    int calculateHashUsingIndexes(vector<vector<int>> v,string s,int start, int end){ // Using the range on the original string
        vector<int> h = v[0], p = v[1];
        return ((h[end] - h[start - 1]p[ end - start + 1])) % B;
    }

    int calculateHashUsingSubstring(string s, vector<vector<int>> v){
        vector<int> h = v[0];
        return (h[s.length()-1]);
    }


    string longestCommonPrefix(vector<string>& strs){
        string a = "";

        int i = 0;

        while(i < strs.size()){


        }
    }


int main()
{
 
    
    cout << endl;
    return 0;
}