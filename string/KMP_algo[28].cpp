
// knuth-morris-pratt: algorithm

#include<bits/stdc++.h>
using namespace std;

// this algo is useful for matching the pattern string in the T.C of O(N + M)

int strStr(string haystack, string needle) {
    int j = 0;

    vector<int>lps(needle.length(),0); // longest prefix suffix array

    int prevLps = 0, i = 1; // here we have initialized hte prevLps (prefix pointer)
    // and i as a suffix pointer


    // formation of longest prefix and suffix array

        while(i < needle.length()){


        if(needle[i] == needle[prevLps]){ // if suffix matches prefix then we will increase the put the prevLps+1 in the array which simply means that (prevLps+1) suffix matches with (prevLps+1) prefix
            prevLps++;
            lps[i] = prevLps;
            i++;
        } else if(prevLps == 0){ // It is for the case wheen we the suffix is not matching with even the first prefix
            lps[i] = 0;
            i++;
        } else { // it is saying to the current char that you couldn't be matched with the current char so just try to start matching with the *prefix* of the previous char
            prevLps = lps[prevLps-1];
        }
    }

    i = 0; // ptr for haystack
    j = 0; // ptr for needle

    while(i < haystack.length()){

        if(haystack[i] == needle[j]){ // here we are simply checking the case whether they are matching or not
            i++;
            j++;
        }  else {
            if(j == 0){
                i++;
            } else {
                j = lps[j-1];
            }
        }

        if(j == needle.length()){ // returning the index of the first element of the substring which matched the needle.
            return i-needle.length();
        }
    }
    return -1;
}


int main()
{
    string h = "sadbutsad",n = "ababaca";

    // n = "but";s3w

    // check(n);

    cout << strStr(h,n);

    cout << endl;
    return 0;
}
