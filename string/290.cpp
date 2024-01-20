#include<bits/stdc++.h>
using namespace std;

vector<string> trim(string s)
    {
        vector<string> str;
        cout << "leng: " << s.length() << endl;
        int i = 0 , begin=0, end=0;

        while(end < s.length())
        {
            while(s[end] != ' ' && end < s.length())
            {
                end++;
            }
             str.emplace_back(s.substr(begin , end-begin));

             end = end+1;
             begin = end;

        }

        return str;
    }

    bool wordPattern(string pattern, string s) {

        int i =0;
        vector<string> str = trim(s);

        unordered_map<char , int> p;
        unordered_map<string , int> k;

        if(pattern.length() != str.size()) return false;

        while(i < pattern.length())
        {

            if( p[pattern[i]] != k[str[i]]) return false;

           p[pattern[i]] = k[str[i]] = i+1;
           i++;
        }

        return i==pattern.length();
        
    }

int main()
{
    
    string s = "dog cat cat fish";

    int i =0;
  vector<string> str = trim(s);



    cout << endl;
    return 0;
}