
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define ll long long
#define F first
#define S second
#define ln(s) ((int)(s).length())
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define sst stringstream

/*
    I had my apporach but still this approach works why?
    because, this approach is efficient like I have totally cutdown the
    need of the assigning lot of time to a worker while anyother worker
    remains idle and I will get to realisee this thing only after the end of the
    jobs array but with this approach i can see it soon, second there's no need of
    any max time calculations as we are suggesting the max time

    one approach of mine was good is to understand the need of the subsequence
    and therapply the right way to get them
*/

class Solution {
public:
    // it is saying that divides the all array in k subsequence such that the
    // maximum among the k subsequence should be minimized
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int ans = INT_MAX;
        vi wt(k, 0);
        int r = accumulate(begin(jobs), end(jobs), 0), l = 1;

        while (l <= r) {
            int mid = l + ((r - l)>>1);
            bool can = sol(0,jobs,mid,wt,k);
            if (can)
                r = mid - 1;
            else
                l = mid + 1;

            wt.assign(k,0);
        }
        return l;
    }

private:
    // can through max time "time" can we for the subsets including all the
    //  elements of the jobs and none of the worker should remain jobless
    bool sol(int ind, vi& jobs, int& time, vi& wt, int& k) {
        if (ind == sz(jobs))
            return 1;

        for (int i = 0; i < k; ++i) {

            if (wt[i] + jobs[ind] <= time) {
                // take
                wt[i] += jobs[ind];
                if (sol(ind + 1, jobs, time, wt, k))
                    return 1;
                // not take
                wt[i] -= jobs[ind];
            }

            if (wt[i] == 0) // we don't want any worker to be unassigned
                return 0;// and if the worker is remaining unassgned if don't give it
                // the current work then it won't become
        }
        return 0;
    }
};

int main(){

    return 0;
}
