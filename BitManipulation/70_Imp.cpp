#include<bits/stdc++.h>
using namespace std;

    //So here is the concept of entry Ticket if you observe the binary upto the subsets level then you will find something that 
    // (2^n - 1) contains number of bits equal to the size of the array

    // so if we check the bit form of each number from 0 to (2^n - 1) then you are able to make the subsets you want by just addding 
    // the element to an individual array only if there exists 1 in the binary representation of the same index as of the element

    // for example: let take arr = {1,2,3};

    // so here 2^n - 1 == 7 

    // 0 to 7 => 000 , 001, 010, 011, 100, 101, 110, 111

    // so if we say that the bits are telling us whether to take the number in the array or not if there exist a 1 at the same index as 
    // the element in the original array 

    // let's take 001 so there is one only at index 0, so only the element at the index 0 of the original array will be in the "temp" array
    // and no one else while at 110 , index 1 and 2 are having 1 so elements of the corresponding index will be inside the "temp" array.


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        int subsets = 1 << n;

       int entryTicket = 0;

       while(entryTicket < subsets){

            int j = 0;

            vector<int> temp;

            while(j < nums.size()){

                if(entryTicket & (1 << j)){
                    temp.emplace_back(nums[j]);
                }
                j++;
            }

            ans.emplace_back(temp);
            entryTicket++;
       }

        return ans;
    }

int main()
{
 
    
    cout << endl;
    return 0;
}