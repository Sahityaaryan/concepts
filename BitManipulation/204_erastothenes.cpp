#include<bits/stdc++.h>
using namespace std;


//    Sieve of erastothenes



// Need of again explainations :- 

// sieve till roots :- 1. precomputation (creation of an array which will tell whether the number is prime or not in O(1) time complexity) 2.Then simple iteration to check whether a given number is prime or not using precomputed array which we have created

int countPrime(int n){

       vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;// //    sieve of erastothenes


        // precomputation

        for(int i = 2; i <= sqrt(n); i++){

            if(primes[i]){
                for(int j = i*i; j <= n; j+=i){
                    primes[j] = false;
                }
            }
        }

        int counter = 0;

        for(int i = 2; i < n; i++){
            if(primes[i]) counter++;
        }

        return counter;
}





// T.C  = O(N*loglogN)

// sieve till roots

    int countPrimes(int n){

     vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;// //    sieve of erastothenes

// T.C  = O(N*loglogN)

// sieve till roots

        int counter = 0;

        // counter = n-1;

        for(int i = 2; i<= sqrt(n); i++){
            
            if(primes[i]){
                for(int j = i*i; j <= n; j+=i){
                    // if(primes[j]) counter--;
                    primes[j] = false;
                }
            }
        }
                    // if(primes[j]) counter--;
        for(int i = 2;i <= n;i++){
            if(primes[i]){
                counter++;
            }
        }

        if(primes[n]){
            counter--;
        }

        return (counter == -1 ? 0:counter);

    // S.C : O(N)
    // T.C : O((n)* (loglog( sqrt(n) )) + O(n))
    }

// *************** Below method will save you from running another loop for making an array of all the primes but it is still very costly

    // int countPrimes(int n) {
    //     int cnt=0;
    //     vector<bool>prime(n+1,true);
    //     prime[0]=prime[1]=false;
    
    //     for(int i=2;i<n;i++){
    //          if (prime[i]){
    //             cnt++;
    //             for(int j=2*i;j<n;j=j+i){
    //                 prime[j]=0;
    //             }
    //          }
    //     }
    //     return cnt;
    // }

int main()
{
 
    
    cout << endl;
    return 0;
}