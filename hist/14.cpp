#include<bits/stdc++.h>
using namespace std;



#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long
#define F first
#define S second
#define ln(s) (int)s.length()
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>


/**
 *
 * Leetcode (1432) :-> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
 */


class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = sz(cp), score = 0, sum_to_be_ignored = 0;

        // here we will analyze all the possible sums, undere the given conditions
        // and then we'll see which among them is maximum

        int total = accumulate(all(cp),0);

        for(int i = 0; i < (n-k);++i) sum_to_be_ignored+=cp[i];
        score = total - sum_to_be_ignored; // case when we have included all the
        // k elements from the end

        for(int i = n-k; i < n; ++i){
            sum_to_be_ignored += cp[i];
            sum_to_be_ignored -= cp[i-(n-k)];
            score = max(score, total - sum_to_be_ignored);
        }



        return score;
    }
};


int main(){

    return 0;
}
