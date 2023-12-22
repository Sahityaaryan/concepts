#include<bits/stdc++.h>

using namespace std;

	int search(string pat, string txt) {
	   vector<int> m(26,0),r(26,0);
	   
	   int i = 0,k=pat.length(),n = txt.length(),count=0,lead,lag;
    
    if(k== 0 || n==0) return 0;	   
	   
	   while(i < k)
	   {
	        m[pat[i]-'a']++;
	        r[txt[i]-'a']++;
	        i++;
	   }
	   
	   if(m==r) count++;
	   
	   lead = i,lag=i-k;
	   
	   while(lead < n)
	   {
	       r[txt[lead]-'a']++;
	       r[txt[lag]-'a']--;
	       
	       if(m==r) count++;
	       
	       lead++;
	       lag++;
	   }
	   
	   return count;
	   
	   //time: o(n) n=max size
	   //space: o(1)
	   
	   
	   
	}

int  main()
{

    return 0;
}