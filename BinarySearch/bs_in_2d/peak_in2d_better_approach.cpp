#include<bits/stdc++.h>
using namespace std;
    // *********** Problem : Now the code requires to have a peak element in the entire array not for a local area 

    // 2. How can apply I bs means there is no order among the rows or columns either if i am rejecting one side on basis of what?

    // * Ans: So, yes you are correct this is not completely  good to do so but still we can afford this because the testcase will 
    // always has either one (when rows are only two) or more than one peak (when it has more than 2 rows and cloumns) so as you see there
    // are many possible peaks so if we ignored some then also it didn't matter. second when we found that the upper element or the lower
    // element is greater than the current peak it simply means that lower or upper element is greater than all the elements in the 
    // entire row containing the current peak as the current peak is the max element found in that row. so there is something fixed in 
    // and ordered in this approach as well which is helping us to find a local peak element.

     int colOfPeakElement(vector<int> arr) { // actually finding the maximum peak elements
        int i = 0,n = arr.size(), maxi = INT_MIN,col=0;

        while(i < n){

            if(maxi < arr[i]){
                maxi = arr[i];
                col = i;
            }
            i++;
        }
        return col;
     }

    // Time complexity: log(ROWS) X COLUMNS 

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // the answer is whosoever fullfills the checker condtion will be our answer

        int i = 0, currentPeakCol,currentPeak;
           int m = mat.size(), n = mat[0].size();
        int up,down,lo = 0, hi = m-1,mid;

        while (lo <= hi) {

            mid = lo + (hi-lo)/2;

            currentPeakCol = colOfPeakElement(mat[mid]);
            currentPeak = mat[mid][currentPeakCol];

            // edge cases handling

            up = mid>0 ? mat[mid-1][currentPeakCol]:-1;
            down = mid < m-1 ? mat[mid+1][currentPeakCol]:-1;

            if (currentPeak > up && currentPeak > down) { 
                return {mid, currentPeakCol};
            } else if(currentPeak < up){
                hi = mid-1;
            } else {
                lo = mid + 1;
            }
        }
        return {-1, -1};
    }

int main()
{
 
    
    cout << endl;
    return 0;
}