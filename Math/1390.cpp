#include<bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int sum = 0;
            int count = 0;
            
            for (int i = 1; i <= sqrt(num); ++i) {

                if (num % i == 0) { 
                    if (i != num / i) { // if on squaring the divisor we aren't getting hte number then it means it has two different divisors so we are adding both of them together 
                        sum += i + num / i;
                        count += 2;
                    } else {
                        sum += i;
                        count += 1;
                    }
                }
                if (count > 4) break;
            }
            
            if (count == 4) {
                totalSum += sum;
            }
        }
        
        return totalSum;
    }

int main()
{
    
    cout << endl;
    return 0;
}