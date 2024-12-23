#include<bits/stdc++.h>
using namespace std;


int upperBound(int arr[],int target, int n){

      int l = 0, r = n-1;

      while(l <= r){
          int m = l + (r-l)/2;

          if(arr[m] > target) r = m-1;
          else l = m+1;
      }

      // if(arr[r] < target) return l;
      return l;
  }

  int minSteps(int a[], int n, int k) {
     sort(a, a+n);


  //   the whole idea for this question you have to check the reduce and removal case for each step

  // here you have to find that how many numbers has the coins greater than the a[i] + k and then you have to
  //check how many coins do you need to remove from them to make it equal to a[i] + k and note as you are moving
  // ahead in your pointer means you are leaving all the previous coin piles so you have to add the coins of
  // those previous coin piles too.

     vector<int> prefix_sum(n,0);

     prefix_sum[0] = a[0];

     for(int i = 1;i < n; i++) prefix_sum[i] = prefix_sum[i-1]+a[i];


       int coins_removed = INT_MAX;
      int temp_coins;

      for(int i = 0; i < n; i++){

          if(i > 0 && a[i] == a[i-1]){
              coins_removed = min(coins_removed,temp_coins +  ((i > 0)? prefix_sum[i-1]:0));
              continue;
          }

          int idx = upperBound(a, a[i]+k, n);
          int noc = (n-idx);

          temp_coins = (prefix_sum.back() - ((idx > 0)? prefix_sum[idx-1]:0)  - noc*(a[i] + k));

          coins_removed = min(coins_removed, temp_coins + ((i > 0)? prefix_sum[i-1]:0));

      }

      return coins_removed;

  }

int main(){

    return 0;
}
