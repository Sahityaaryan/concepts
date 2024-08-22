#include <bits/stdc++.h>
using namespace std;



// You can also check sieve of eratosthenes



//* Here I have learnt that how the maximum possible divisor of n will be sqrt(n) and how can i apply sieve of eratosthenes by dividing the numbers completely by the prime number I got

vector<int> AllPrimeFactors(int n)
{

    vector<int> k;
    for (int i = 2; i <= sqrt(n); i++) // here know that the maximum possible divisor of n will be sqrt(n)
    {
        if (n % i == 0)
        {
            k.push_back(i);
            while (n % i == 0) // by this we are removing any multiple of i ever present as a factor from 2 to sqrt(n) (as we are not doing sieve of eratosthenes but the method is quite similar as we are removing every multiple of primes we get)
            {
                n /= i;
            }
        }

        if(n == 1){
            break;
        }
    }

    if (n != 1)
        k.push_back(n);


        // T.C = O(Total number of times any prime factors appear while taking the lcm of the number)

    return k;
}

int main()
{
    vector<int> prime = AllPrimeFactors(2);

    cout << "ans:\n";

    for (int i : prime)
    {
        cout << " " << i;
    }

    // if(2 % 2 == 0){
    //     cout << "2 is not a prime number";
    // } else {
    //     cout << "2 is a prime number";
    // }

    cout << endl;
    return 0;
}

#