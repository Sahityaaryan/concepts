
// # Question: https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679




#include<bits/stdc++.h>
using namespace std;

//* Here the best part is that we are checking for the overflow condition at the moment we are calculating the multiply to n times


long long mul(int n, int k, int m)
{

    long long ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= (long long)n;
        if(ans > m) {
            ans = -1;
            break;
        }
    }

    return ans;
}

int NthRoot(int n, int m)
{
    if (n == 1)
        return m;

    int hi = (m >= 4) ? m / 2 : m;

    int lo = 1, mid;
    long long compute;


    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        compute = mul(mid, n, m);

        if(compute == -1){
             hi = mid-1;
             continue;
        }


        if (compute < (long long) m)
        {
            lo = mid + 1;
        }
        else if (compute > (long long) m)
        {
            hi = mid - 1;
        }
        else
        {
            return mid;
        }

    }

    return -1;
}
// 217013

int main()
{

    cout << NthRoot(9,1953125);
 
    
    cout << endl;
    return 0;
}