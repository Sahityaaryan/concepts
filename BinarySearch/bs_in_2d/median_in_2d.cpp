
#include <bits/stdc++.h>
using namespace std;


// striver says that: T.C = R * log(C)

// me =  T.C = log(R*C)*(R * log(C)); // because we actually want to find that number who is in middle of that array which is formed when all the elements are included into it in sorted order.

// this will take a long time to fix things on the place
// Main Idea; the median has fixed number of numbers before it.

// ***** Questions: 
//! 1. first how it is making sure that the number is existing in the vector means it is caluclating 
// just a mid without making sure wheter the never is existing or not ?

// * Ans: Got it actually if you see the mechanism cleary so you will find that it is trying to get the lowest number whose count is greater than the  number of count (elements before the median without including it) and also searching for the highest number whose number of elements before and including it is just greater than count. --> so by this basically we are finding the lowest possible answer whose number of elements before and including it is equal to the count which is nothing but the median itself and that's how we are making sure that the assumed median is existing. 

//! 2. why we have to give lo as to increment the count? while calculating the (total number  of numbers less than the given number in the entire array)\
// * Ans: Just check the upperBound in the BinarySearch/problems dir.


int calculateTheLessNumber(vector<vector<int>> v , int mid){

    int i  = 0,j = 0,count = 0;

    while(i < v.size()){
        
        vector<int> arr = v[i];
        int lo = 0, hi = v[i].size()-1;
        int ind;
        
        while(lo <= hi){
            ind = lo + (hi-lo)/2;
            
            if(arr[ind] <= mid){
                lo = ind+1;
            } else {
                hi = ind-1;
            }
        }
        
        
        count += lo; // ok I know that hi would be the correct index for it which has the upperBound index of the target but we want number of elements which are more than the target so it is hi+1 which is nothing but the lo.
        i++;
    }
    return count;
}


int median(vector<vector<int>> &matrix, int R, int C){
    int mid, lo = INT_MAX, hi = INT_MIN, i = 0, j = 0, count = (R * C + 1) / 2;
    
    // del
    count = (R*C)/2;
    int ans;

    while (i < R){
        
        lo = min(matrix[i][0], lo);
        hi = max(matrix[i][C - 1], hi);
        i++;
    }

    i = 0;
    
    // Note: this is the bs when the count is defined as the number of elements before the median without including it,

    // while (lo <= hi){
    //     mid = (lo + hi) / 2;

    //     int numbers = calculateTheLessNumber(matrix,mid);
        
    //     if(numbers <= count){
    //         lo = mid + 1;
    //     } else {
    //         hi = mid-1;
    //     }
    // }
    
    count++;
    
    // Note: this the bs when the count is defined as the number of elements before the median, including it as well,
    
        while (lo <= hi){
        mid = (lo + hi) / 2;

        int numbers = calculateTheLessNumber(matrix,mid);
        
        if(numbers < count){
            lo = mid + 1;
        } else {
            hi = mid-1;
        }
    }
    
    // Note: both of the method are checking like: if you got a number which is satisying the condition throw it in the hi, and check for the lowest 
    // element which barely fulfilling the required condition (a particular count of the numbers more than)

    return lo;
    // return ans;
}

int main(){


    return 0;
}