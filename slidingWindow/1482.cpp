

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Approach

//tab tak days search karo minimum number of days mein jab tak 
//tumhe consecutive all number of boqeuts nahi mil jaate 

// Methods of doing it -linear search extreme danger case 


//1. this is checking that whether upto the given minimum number of days (mid)
//how many boquets can be formed if we have to choose adjacent flowers
int isAmple(vector<int> v,int k,int mid)
{

    int required_adjacent_flowers = 0, number_of_required_boquets =0,i = 0,n = v.size();

    while(i < n)
    {
        if(v[i]<=mid)
        {
            //if the time to bloom the flower is less to out minimum chose day then 
            //take the flower of that day
            required_adjacent_flowers++;

            if(required_adjacent_flowers==k)
            {
                //if the number of required flower you have founded till now is equal 
                //to the required no. flower to make a boquet then make the boquets 
                //nd go to fetch mnore flowers
                number_of_required_boquets++;
                required_adjacent_flowers = 0;
            }
        }
        else
        {
            //this is the condition when you found a day higher then the minimum chosen
            //day and that's why you are not able to continue chose you flowers and have
            //to start from the other flower because the adjancy is broken and non
            //adjacent flowers can't be accepted 
            required_adjacent_flowers = 0;
        }
        i++;
    }

    return number_of_required_boquets;

}

int minDays(vector<int> &bloomDay, int m, int k)
{

    if (m * k > bloomDay.size())
        return -1;

    int low,high,mid,possible_number_of_flowers;

    //just setting up the maximum element of the array and the minimum one
    low = *min_element(bloomDay.begin(),bloomDay.end());
    high = *max_element(bloomDay.begin(),bloomDay.end());


    while(low <= high)
    {
        //this is the amazing method of chosing mid as it avoid the casee when you will find 
        //the same mid
        mid = low + (high-low)/2;

        possible_number_of_flowers = isAmple(bloomDay,k,mid);

        if (possible_number_of_flowers >= m)
        {
            //if we got the possible number of flower in the assumed minimum day
            //then we will choose to again assume for a less minimum number of day 
            //possible to make the boquets 
            high = mid-1;
       
        }
        else
        {
            //if we don't get the required number of flowers then we have to set 
            //our assumed minimum number of day more higher to get the required 
            //number of flower
            low = mid+1;
         
        }
    }


    return low;
}

// my approach of solving this



int main(){ 

    // vector<int> bloomDay = {1,10,3,10,2};
    vector<int> bloomDay = {5, 37, 55, 92, 22, 52, 31, 62, 64, 92, 53, 34, 84, 93, 50, 28};

    // cout << bloomDay.size() << endl;
    // vector<int> bloomDay = {7,7,7,7,12,7,7};

    // int m = 3;
    // int k = 1;
    int m = 8;
    int k = 2;

    cout << "ans: " << minDays(bloomDay,m,k);
    cout << endl;
    return 0;
}