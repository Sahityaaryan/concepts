
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int sol(string &s,int k)
{
    //here is the solution of the above questions

    //1. creating the frequency map of all the chars

    //* there are 256 ASCII chars 

    int hsh[26]={0};
    //leader and lagger approach (aka sliding window)

    int leader=0,lagger=0,max_frequency = 0,distance=0,ans=0;

    while( leader < s.size())
    {
        //calculating the frequency dynamically becuase we just have to maintain the frequency of all the chars inside the window
        hsh[s[leader]-'A']++;

        //calculating the max frequency inside the window in betweeen leader and lagger of any char except the k chars in between them
        max_frequency = max(max_frequency,hsh[s[leader]-'A']);


         // calculating the distance or width of the window of the required case (in which if we replace the
         // different chars (the chars of not the max frequency inside the window) )
         distance = leader - lagger + 1;

        if (distance- max_frequency > k)
        {
            // move the lagger one step ahead because the leader has moved one step ahead and
            // the window size should remain constant and also you have to remove the frequency of that charcter which is now not the part of the window so that you are able to manage the frequencies of 
            //the chars inside the window only and able to calculate the maximum frequency of any char inside the window 

            hsh[s[lagger] - 'A']--;

            lagger++;
            max_frequency--;
        }
        else
        {
            //here the window will grow till we got the (max frequency chars + k different chars of less frequency) and actually this is the true width of our required window
            ans = max(ans,distance);
        }

        leader++;
        
    }

    return ans;


}

int main(){
    string s = "AAABABBA";
    int k = 1;
    // cout << f2(s,k);
    cout << sol(s,k);
    cout << endl;
    return 0;
}


