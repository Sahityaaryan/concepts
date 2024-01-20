
//  # ****************************** Notes:****************************

//% 1. Input 

//* getline(cin , string_var_name) // to take the whole line as an input

//*  ">>" this is known as extraction operator "cin >> " by this it will consider : tab, space and newline characters as ending of the string 

// % 2. Ascii values

//* checkout the your whatsapp for a table 
// * a = 97 and z = 122 || A = 65 and z = 90

//% 3. String V/s character Array

// * 1. string is a class and all the string variables are objects of this class
// * 2. It has dynamic memory allocation 
// * 3. no pre-allocated memory so there is no wastage of memory in it 
// * 4. Have inbuilt functions.
// * 5. charcter array has more faster implementations as compare to the string 

 

#include<bits/stdc++.h>
using namespace std;


//! Challenge 1

void sortInLexicoGraphicOrder(string& str)
{
    int i = 0 , n = str.size();

    vector<int> v(n);

    while(i < n)
    {
        v[i] = (int) str[i];
        i++;
    }

    sort(v.begin(), v.end());

    str = "";


   i = 0;
   while(i < n)
   {
        str += v[i++];
   }

}




int main()
{

    string str = "Jai Mata Di";

    // # some usefull functions

    // % 1. reverse (T.C = O(length of string))

    // * str.begin() = an "iterator" which is pointing to the beginning of the string 

    
    // reverse(str.begin(), str.end());

    // cout << str;

    // % 2. substr(startIndex, length)

    // cout << str.substr(4,4);

    // % 3. strcat(): 

    // * used to concatenate two character arrays

    // char s1[20] = "jai";
    char s2[20] = " mata di";

    // strcat(s1, s2);

    // cout << s1 << endl;

    // % 4. strlen(): 

    //* returns the length of the character array

    // cout << strlen(s2);

    // ! Note:  
    // * the .size() and .length() mehtods of string has T.C(O(1)) but strlen has T.C(O(N))


    // % 5. to_string():

    // * to convert the a number to a string



    // ! Challenge 1

    string str2 = "star";

  sortInLexicoGraphicOrder(str2);

  cout << str2 << endl;





    cout << endl;
    return 0;
}