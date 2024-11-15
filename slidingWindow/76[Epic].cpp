#include<bits/stdc++.h>
using namespace std;

// string minWindow(string s, string t)
// {
//     vector<int> map(128, 0);
//     for (auto c : t)
//         map[c]++;


//     int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
//     while (end < s.size())
//     {
//        if (map[s[end++]]-- > 0)
//             {counter--; // in t
//             }
//         while (counter == 0)
//         { // valid
//             if (end - begin < d)
//                 d = end - (head = begin);
//             if (map[s[begin++]]++ == 0)
//                 counter++; // make it invalid
//         }
//     }
//     return d == INT_MAX ? "" : s.substr(head, d);

// }


    string minWindow(string s, string t) {
        
        int lead = 0, lag = 0, min_window = 0;
        string requiredString = "";

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        while(lead < t.length()){
            mp1[t[lead++]]++;
        }

        lead = 0;

        while(lead < s.length()){

            if(mp1.find(s[lead]) != mp1.end()){
                mp2[s[lead]]++;
            }

            while(mp2.size() == mp1.size()){

                int window = lead-lag+1;
                if(min_window > window){
                    min_window = window;
                    requiredString = s.substr(lag, min_window);
                }

                mp2[s[lag]]--;
                if(mp2[s[lag]] == 0){
                    mp2.erase(s[lag]);
                    lag++;
                }
            }

            lead++;
        }

        return requiredString;
    }


string minWindow(string s, string t) {
   unordered_map<char,int> map;
    for (auto c : t)
        map[c]++;

    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size()) {
        if (map[s[end]] > 0) {
               counter--;
        }
        map[s[end]]--;
        end++; 

        while (counter == 0) { // valid
            if (end - begin < d) {
                d = end - begin;
                head = begin;
            }
            if (map[s[begin]] == 0) {
                counter++;
            }
            map[s[begin]]++;
            begin++;
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main()
{
 
    string s = "TOTMTAPTAT",t ="TTA";
    cout << minWindow(s,t);
    cout << endl;
    return 0;
}