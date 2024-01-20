#include<bits/stdc++.h>
using namespace std;


//! I donn't know why my the for loop execution of finding the required function is much efficient than using the 2d array for it


   int bestClosingTime(string customers) {  
        int n=customers.length();
       int pre[n+1];
       int suf[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++)
        {
           pre[i+1]=pre[i]+((customers[i]=='N')?1:0);
        }
        suf[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            suf[i]=suf[i+1]+((customers[i]=='Y')?1:0);
        }
        
        int minPen=n;
        for(int i=0;i<=n;i++)
        {
        pre[i]+=suf[i];
        int pen=pre[i];
        minPen=min(minPen,pen);

        }
        for(int i=0;i<=n;i++)
        {
            int pen=pre[i];
            if(pen==minPen) return i;
        }
        return n;
    }


//# Mine answer (Not Optimized)


    vector<int> prefixMaker(string customers,char target)
    {
        int n = customers.length();
        int i = 0, count =0;

        vector<int> prefix(n);

        while(i < n)
         {
             prefix[i] = count;
             if(customers[i]== target)
             {
                 count++;
             }
             i++;
         }

         return prefix;
    }

    int bestClosingTimeMIne(string customers) {

        int n = customers.length(), i, count , minPenalty = INT_MAX,penalty;

        // special prefix sum of Y

        vector<int> prefixY = prefixMaker(customers,'Y');
        vector<int> prefixN = prefixMaker(customers,'N');
        
    vector<int> indices(n+1,-1);

        i = 0;

        bool isNPresent = false;

        while(i < n)
        {
            penalty = prefixN[i] + (prefixY[n-1] - prefixY[i] + 1);

          if(indices[penalty] == -1) indices[penalty] = i;

          minPenalty = min(penalty,minPenalty);

            i++;
        }

    // handle the case when the shops never closes
     penalty = prefixN[n-1];

    if(customers[i-1] == 'N') penalty++;

    if(indices[penalty] == -1) indices[penalty] = n;

      minPenalty = min(penalty,minPenalty);

    return indices[minPenalty];
    } 



int main()
{
    

    
    cout << endl;
    return 0;
}