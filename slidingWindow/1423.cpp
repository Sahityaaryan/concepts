#include<bits/stdc++.h>
using namespace std;
 
 int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    vector<int> prefixSum(k + 1, 0), suffixSum(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        prefixSum[i] = prefixSum[i - 1] + cardPoints[i - 1];
        suffixSum[i] = suffixSum[i - 1] + cardPoints[n - i];
    }

    int maxScore = 0;
    for (int i = 0; i <= k; i++) {
        maxScore = max(maxScore, prefixSum[i] + suffixSum[k - i]);
    }

    return maxScore;
}

int main(){
    
 cout << endl;
return 0;
}