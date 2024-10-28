#include<bits/stdc++.h>
using namespace std;

    void sieve() {}
    
    
    // LCM:
    
    // The method below is literally doing the LCM of the Number as the precomputed array is containing
    // the prime factor from which that index number will be divisible and that's all we want while 
    // calculating the lcm

    vector<int> findPrimeFactors(int N) {
        
     vector<int> ans;
     
    //  creating spf (smallest prime factor)
    
    vector<int> spf(N+1);
    
    for(int i = 2; i <= N; i++){
        spf[i] = i;
    }
    
    for(int i = 2; i <= sqrt(N); i++){
        
        if(spf[i] == i){
            
            for(int j = i*i; j <= N; j+=i){
                
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    
    
    // Now doing the prime factorization
    
    while(N != 1){
        ans.emplace_back(spf[N]);
        N /= spf[N];
    }
    
    return ans;
    
    
    
    // for calculating the SPF
    // T.C : O(N + N(loglog(sqrt(N))) + N )
    // S.C : O(N)
    
    
    // after calculalting the spf
    
    
    // T.C : O(log(N))
    // S.C : O(log(N))
    
    
    // Overall
    
    // T.C : O(N(loglog(sqrt(N))))
    // S.C : O(N)
        
    }

int main()
{
 
        
    cout << endl;
    return 0;
}