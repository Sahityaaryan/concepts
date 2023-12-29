

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestNiceSubarray(vector<int> &nums)
{
    // heren= the answer is the longest sub array length whose elements if converted into bits should not have any common one at a common position

    int leader = 0,lagger = 0,width = 0,i,num;

    int bitMap[31]={0}; //here is the bit map whose work is to place the 1's of every element(binary) at the postion

    //for example if you got {1,9} the its bitMap when it is mapping the 1 in it ={1,0,0,0,0,..31 times} because the binary of 1 contains 1 at 0th position
    //on mapping 8 after mapping the 1 it should look like ={2,0,0,1,0,0,0.. 31 times} because the binary of 9 contains 1 at the 0th postion and 1 at the 3rd
    //position and thus by this concept of binary map will get to know that whether the binary forms of the elements contains 1 at the same positions

    //and its size is 31 because any int variable can have max value upto 2^31

    

    while (leader < nums.size())
    {
        // 1. placing the element one by one in the bitMap
        i=0;
        bool checker_for_same_postion_bits = false;
        while(i < 31)
        {
            if(nums[leader] & (1<<i))
            {
                bitMap[i]++;

                if(bitMap[i]>1)
                {
                    checker_for_same_postion_bits=true;
                }
            }
            i++;
        }

        //if the checker is true that means two elements has got the similar position one

        while(checker_for_same_postion_bits)
        {
            num = nums[lagger];

            //removing every bit of the lagger element from the entire bit map and thus removing the lagger element itself
            i = 0;
            while(i < 31)
            {
                if(nums[lagger] &(1<<i))
                {
                    bitMap[i]--;
                }
                i++;
            }

            //updating the lagger
            lagger++;

            //check again if the bitMap is free from the same position ones or not

            i = 0;
            bool intermediate_checker = false;

            while(i < 31)
            {
                if(bitMap[i]>1){intermediate_checker = true;}
                i++;
            }
            // if intermediate checker is false then it break the loop by setting then original checker = false else the loop will again remove the lagger

            if(!intermediate_checker) checker_for_same_postion_bits = false;

        }

        //here we are not calculating the width until our elements binary haven't the 1 at the similar position because
        //if they have then the condition of the question will got false that if wedo AND operation among the pairs of the element in your window then none of the answer should be 1 at is posiible only when the condition we are checking of 
        //similar postion one is satisfied 

        
        width = max(width,leader-lagger+1);

        leader++;
    } 

    return width;

}

int main(){
    
    vector<int> nums ={1,3,8,48};

    cout << "ans: " << longestNiceSubarray(nums);
    cout << endl;
    return 0;
}