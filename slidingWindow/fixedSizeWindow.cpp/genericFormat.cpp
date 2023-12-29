
//syntax of the fixed size sliding window

#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int i = 0,j = 0;
    int k ;//window size
    int size;// size of the array

    while(j < size)
    {

        //calculations
        
        if(j-i+1 < k)
        {
            j++;
        }
        if(j-i+1==k)
        {
            //1. providing some ans using calculations

            //2.slide the window
            i++;
            j++;
        }

    }

    
    return 0;
}