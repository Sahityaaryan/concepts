#include<bits/stdc++.h>
using namespace std;

    int getvalueofx(int n){
        
        // counting the number of bits one less than the total number of bits required to form the number
        
        int count = 0;
        while((1 << count) <= n){
            count++;
        }

        cout << "n: " << n << " count: " << count << endl;
        return count-1;

        // T.C : O(log(n))
    }
    
    int countSetBits(int n)
    {
        int ans = 0;
        int cnter = 0;

        // cout << ++cnter << '\n';

        if(n == 0)
        return 0;
        
        int x = getvalueofx(n);
        
        int y = (1 << x-1)*x;  // counting the number of bits in the one less thna the total number of bits 
        // like 000 , 001, 010, 011, 100, 101 (so here calculating the number of set bits in the 2 - 5  upto all the bit 
        // positions except the rightmost bit position.
        
        int z = n - (1 << x) +1; // counting the number of set bits in the rightmost position.
        
        ans = y + z + countSetBits(n - (1 << x));
        return ans;

        // T.c : IT's time complexity is something very less than even less than (log(n))(talking of only the parent function not the T.C of 
        // the function used init ) --> I can assume the T.c : O(log(n)) because it is reducing the number of calls to a very huge extent
    }

int main()
{
    int n;
    cin >> n;
    cout << "\nwelcome :\n"<< countSetBits(n);

    
    cout << endl;
    return 0;
}