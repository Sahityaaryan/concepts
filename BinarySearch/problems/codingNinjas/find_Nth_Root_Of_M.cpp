
// # Question: https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679




#include<bits/stdc++.h>
using namespace std;

long long mulToNtimes(int number, int n){
  long long multiplier = number;
  long long num = number;
  while(n--){
    num *= multiplier;
  }

  return num/multiplier;
}

int NthRoot(int n, int m) {

  // checking the for the ntimes multiply of the 

  int lo = 1, hi = m/n;

  while(lo <= hi){

    int mid = lo + (hi-lo)/2;

    long long assumedMultiple = mulToNtimes(mid,n); 

    if(assumedMultiple==(long long)m) return mid;
    else if(assumedMultiple > (long long)m){
        hi = mid-1;
    } else {
      lo = mid + 1;
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