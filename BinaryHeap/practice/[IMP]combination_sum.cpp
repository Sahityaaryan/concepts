#include<bits/stdc++.h>
using namespace std;


// question :-> https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> pair_set;

    // using set to make sure that the  duplicate sum due to duplicate pair of indices won't occur

    for (int i = 0; i < n; i++)
    {
        pq.push({A[i] + B[n - 1], {i, n - 1}});
        pair_set.insert({i, n-1});
    }

    vector<int> ans;

    while (C--)
    {
        auto topNode = pq.top();
        pq.pop();
        int sum = topNode.first;
        int x = topNode.second.first;
        int y = topNode.second.second;
        ans.push_back(sum);
       if(pair_set.find({x, y-1}) == pair_set.end()) {
        pq.push({A[x] + B[y - 1], {x, y - 1}});
        pair_set.insert({x, y-1});
       }
    }
    return ans;
}

int main(){
    
 cout << endl;
return 0;
}