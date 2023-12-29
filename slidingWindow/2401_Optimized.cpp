

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//check this solution commit


//one of the best use of teh bianry operations


int longestNiceSubarray(vector<int> &nums)
{

    //isme "used" hai wo binaryMap ka kamm kar raha hai means isme wo saare jage par one aaja rahe hai jo 
    //pehle pehle main toh the par dusre number main nhi the 

    //fir ye and operation kar raha hai aage wale number se agra kisi bhi position pe ise comman 1 mila
    //toh & greater than 0 output deta hai jaise hi aisa hua means ye time hai lagger ki help se pehle pade 
    //number ke bits ko remove karna and tab tak karna jab tak common one kahatam na ho jaye tab take aage na badhna
    //and ye kaam karne mein help kar raha hai xor operator because xor operator common bits ko 0 kar deta hai means given number
    //ke bits used main jis bhi position main honge un sarre position se kahatam kar dega ya unhe 0 kar dega!!!
    
    //and res width of the window ko mainatian kar raha hai

    int used = 0, j = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        while ((used & nums[i]) != 0)
        {
            used ^= nums[j++];
        //    cout << "j: "<<j << endl;
        }

        used |= nums[i];
        res = max(res, i - j + 1);
    }
 
    return res;
}

int main()
{

    vector<int> nums = {1, 3,12};

    cout << "ans: " << longestNiceSubarray(nums);

    // cout << 1^3;
    cout << endl;
    return 0;
}