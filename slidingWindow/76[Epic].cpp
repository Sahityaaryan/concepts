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