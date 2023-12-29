

#include <iostream>
#include <vector>
using namespace std;

//* perfect example of sliding window

int longestOnes(vector<int> &nums, int k)
{

    
    int i = 0, j = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            if (nums[i] == 0)
            {
                k++;
            }
            i++;
        }
        j++;
    }
    return j - i;
}
int main()
{
    vector<int> v={1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << longestOnes(v,2);
    return 0;
}