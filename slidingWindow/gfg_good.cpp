#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    
    if (k==0) return 0;
        
        int i,lead=0,lag=0,size = -1,n=s.length();
        
        unordered_map<char,int> m;
        
        
        while(lead < n)
        {   
           m[s[lead]]++;

            if(m.size()>k)
            {
                m[s[lag]]--;
                if(m[s[lag]]==0) m.erase(s[lag]);
                
                lag++;
            }
            
            if(m.size()==k) {
         size = max(size,lead-lag+1);
            }
            
            lead++;
        
            
        }
        
        return size;
           
    }
int main()
{
 
 cout << longestKSubstr("aabacbebebe",3);
    
    cout << endl;
    return 0;
}