#include<bits/stdc++.h>
using namespace std;


//* Sir's apprach

    // here i have implemented two pointer approach 

    // 1. we will check if at any side the height is less than the opposite side then before storing the water we will check whether the max of that side is greater than
    // the height if yes then we can store water of area (max - height) otherwise we can't and we have to move further

    // 2. If we find any equal elements then it depends on us which side we choose to move (can be left or can be right)

    int trap(vector<int>& height) {
        int area = 0, l = 0, r = height.size() - 1, l_max = 0, r_max = 0;

        while (l != r) {

            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);
            for(int i = 0; i < height.size(); i++) {
                if(height[i] > l_max) {

                    l_max = height[i];
                }
            }
            if (height[l] != height[r]) {
                if (height[l] < height[r]) {
                    if (l_max > height[l]) {
                        area += (l_max - height[l]);
                    }
                    l++;
                } else {
                    if (r_max > height[r]) {
                        area += (r_max - height[r]);
                    }
                    r--;
                }
            } else {
                r--;
            }
        }
        return area;

        // T.C : O(N)
        // S.C : O(1)
    }

int main()
{
  
  cout << endl;
  return 0;
}
