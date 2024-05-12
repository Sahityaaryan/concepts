#include<bits/stdc++.h>
using namespace std;

// this will take a long time to fix things on the place

int median(vector<vector<int>> &matrix, int m, int n) {
    int ps = (m*n)/2, midRow,midCol;
    int lo = 1,hi = ps,mid,mid1,mid2;
    int rowPosit1,rowPosit2,rowPosit3,rowPosit4;
    int colPosit1,colPosit2,colPosit3,colPosit4;
    int leftUpper,leftLower,rightUpper,rightLower;
    int mini1,mini2;

    midRow = ps/m,midCol = ps%n-1;

    if(ps%m==0){
        midRow--;
    } 

    if(ps%n==0){
        midCol = n-1;
    }

    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        mid1 = mid;
        mid2 = ps-mid;

        // calculating row and column indices of the leftn upper

        int rankOfLeftLower = ps + mid2 -1;

        rowPosit1 = mid1;rowPosit3 = rowPosit1;

        if(mid1%m==0){// when we have chosen the last member of a row
            rowPosit1--;
        }

        colPosit1 = mid1%n-1;colPosit3 = colPosit1+1;

        if(mid1%n==0){ // when we have chosen the last member of a row
            colPosit1 = n-1;
            colPosit3 = 0;
        }

        int i = 0;
        leftUpper = matrix[rowPosit1][colPosit1];

        while(i < rowPosit1){
            leftUpper = max(leftUpper,matrix[i][n-1]);
            i++;
        }

        // leftUpper

        rowPosit2 = rankOfLeftLower/m;rowPosit4 = rowPosit2;

        if(mid2%m==0){// when we have chosen the last member of a row
            rowPosit2--;
        }

        colPosit2 = rankOfLeftLower%n-1;colPosit4 = colPosit2+1;

        if(mid2%n==0){ // when we have chosen the last member of a row
            colPosit2 = n-1;
            colPosit4 = 0;
        }


        leftLower = matrix[rowPosit2][colPosit4];
        
        while(i < rowPosit2){ // check here !!!!!!!!!!!!
            leftLower = max(leftLower, matrix[i][n-1]);
            i++;
        }

        // stiching

        rightUpper = matrix[rowPosit2][colPosit2];

            

        i = rowPosit3+1;

        while(i <= midRow){
            rightUpper = min(rightUpper,matrix[i][0]);
            i++;
        }

        rightLower = matrix[rowPosit4][colPosit4];

        i = rowPosit4 == m-1 ? m-1:rowPosit4+1;

        while(i < m){
            rightLower = min(rightLower,matrix[i][0]);
            i++;
        }


        if(rightUpper < leftLower && rightLower < leftUpper){
            return min(rightLower,rightUpper);
        } 

        if(rightUpper > leftLower ){
            hi = mid-1;
        } else {
            lo = mid+1;
        }

    }

    return -1;        

}

int main()
{
 
    
    cout << endl;
    return 0;
}