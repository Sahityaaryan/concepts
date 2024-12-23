#include<bits/stdc++.h>
using namespace std;

// Learning :-> In this question you just have to focus on the given conditions only as in the conditions
// nothing is said about the case when the ratings are equal so it means that they can differ and may not
// be equal

int candy(vector<int>& r){
    int n = r.size();
    vector<int> c(n,1);

    // left pass

    for(int i = 1; i < n ; i++){
        if(r[i-1] < r[i]) c[i]=c[i-1]+1;
    }

    for(int i = n-2; i>=0; i--){
        if(r[i+1] < r[i] && c[i+1] >= c[i]) c[i] = c[i+1]+1;
    }


            int noc = 0;
        // summing the min candies

        for(int ele:c){
            noc += ele;
        }

        return noc;

        // T.C : O(2N)
        // S.c : O(N)
}




// MY solution

// //  The T.C is poor because there is a possible way that I have to traverse backward multiple times but if do with left to right and right to left pass all the things will get done within just O(2N) T.C
//     int candy(vector<int>& r) {
//         vector<int> c(r.size(),1);
//         c[0] = 1;

//         // yes there is another way of right to left and left to right pass

//         for(int i = 1;i < r.size(); i++){

//             if(r[i-1] > r[i]){

//                 // back propagation

//                 int j = i-1;
//                         while(j >= 0 && r[j+1] < r[j]){
//                             if(c[j] <= c[j+1]) {c[j]++;}
//                             else break;
//                             j--;
//                         }

//             } else if(r[i-1] < r[i]){
//                 c[i] = c[i-1] + 1;
//             }
//         }
//         int noc = 0;
//         // summing the min candies

//         for(int ele:c){
//             noc += ele;
//         }

//         return noc;
//     }

int main(){

    return 0;
}
