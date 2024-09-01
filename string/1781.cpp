#include <bits/stdc++.h>
using namespace std;

    int beautySum(string s) {
        int i = 0, j = 0, lagger = 0, beauty = 0,hi,lo,dist_count, count=0 , n =s.length();

        while(i < n-1){
            j = i;
            vector<int> freq(26,0);

            while(j < n){

            lo = INT_MAX,hi = INT_MIN;

                freq[s[j]-'a']++;

                    int k =  0;

                    while(k < 26){
                      if(freq[k]){
                        hi = max(hi,freq[k]);
                        lo = min(lo,freq[k]);
                      }
                        k++;
                    }

                    beauty += (hi-lo);
                j++;
            }
            i++;
        }

        return beauty;
    }


int main()
{
    string s = "aabcb";

    s = "xzvfsppsjfbxdwkqe";

    cout << (s.length()*(s.length()+1))/2 << endl;

    // s = "aabc";

    cout << "answer: " << beautySum(s) << endl;

    cout << endl;
    return 0;
}
