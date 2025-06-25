#include<bits/stdc++.h>
using namespace std;


//* Sir's apprach

    // here i have implemented two pointer approach

    // 1. we will check if at any side the height is less than the opposite side then before storing the water we will check whether the max of that side
    // is greater than the height if yes then we can store water of area (max - height) otherwise we can't and we have to move further

    // 2. If we find any equal elements then it depends on us which side we choose to move (can be left or can be right)

 int trap(vector<int>& height) {
        int area = 0, l = 0, r = height.size() - 1, l_max = 0, r_max = 0;

        while (l != r) {

            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

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
    }


// Here is the follow up question where we have to find the maximum stored water

 int maximumTrappedWater(vector<int>& height) {
        int area = 0, l = 0, r = height.size() - 1, l_max = 0, r_max = 0, max_area = INT_MIN;
        bool isContinousStorage = false;

        while (l != r) {

            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if (height[l] != height[r]) {
                if (height[l] < height[r]) { // this condition is to check whether it can store the water or not
                    if (l_max > height[l]) {
                        area += (l_max - height[l]);
                        // cout <<"\narea: " << area ;
                    } else {
                        max_area = max(max_area, area);
                        area = 0;
                    }
                    l++;
                } else {
                    if (r_max > height[r]) {
                        area += (r_max - height[r]);
                        // cout <<"\narea: " << area ;
                    } else {
                        max_area = max(max_area, area);
                        area = 0;
                    }
                    r--;
                }
            } else {
                r--;
            }
        }

         max_area = max(max_area, area);

        return max_area;
    }


int main()
{

    vector<int> h = {1,0,2,0,2,5,0,5};

    cout << "\nAns: " << maximumTrappedWater(h);

  cout << endl;
  return 0;
}
