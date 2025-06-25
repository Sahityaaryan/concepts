

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//##########  New things learnt ###############//

//* jumping window 


//* The ‘fill’ function assigns the value ‘val’ to all the elements in the range [begin, end), 


//1.  using "int arr[23]={-1} will only initialize the first element of the array to -1 but the other element will be zero"
// use "fill(address_of_first_element , address_of_first_element + size, content_you_want_to_fill)"


int lengthOfLongestSubstring(string s)
{

    // here I have to find the longest non-repeating substring

    //METHOD -  here I will first try to gain the longest width of substring till the first character of that substring is
    //not repeated if i found that element again then I again point my lagger to just a one character ahead of it

    int len = s.length(), lagger = 0, leader = 0, width = 0;

    //here this index will store the index of each distinct character of the substring so that i can know that if a char is repeated 
    //then what was its previous index to set my lagger just one char ahead of it and thus calculating the length of the window

    //but note that i initialized it with "-1" means that initially it is not having any Index at all in it
    int charIndex[128];

    fill(charIndex,charIndex+128,-1);

    //Lagger - it is storing the index of the first charcter of our non-repeating substring 
    while( leader < len)
    {
        if (charIndex[(int)s[leader]] >= lagger)
        {
            lagger = charIndex[(int)s[leader]] + 1; 
        }
        
        // storing the index of the each character into the charIndex
        charIndex[(int)s[leader]] = leader;

        // cout << "distance: "<<leader-lagger+1 << endl;

        width = max(width,leader-lagger+1);

        leader++;
    }

    return width;

    // Questtion 1 - why if the lagger is the index of the first char of the window and wee are searching that whether it repeats in the a
    // string or not then why we have given  condition (charIndex[s[leader]] >= lagger) it should be rather "==" only ?

    //Answer - because we are not checking that whether the first element is repeating or not may be anyother character of that windoe repeats
    //so we also have to consider the repeating of other char of the window accept the first char of the window and update our lagger accordingly
    // Example - "abcbacba" -- "here the second char repeats before the first char of the window"
}

    int main()
    {
        string s = "b";

        cout << "ans: " << lengthOfLongestSubstring(s);
        cout << endl;
        return 0;
    }
