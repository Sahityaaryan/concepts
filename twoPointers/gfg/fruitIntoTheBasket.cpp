#include<bits/stdc++.h>
using namespace std;
 

int totalFruits(vector<int> &arr) {
        
        // Here the concept is very clear but this questio  has taught me that don't rely always on window size they may fail
        
        int i = 0, lagger = 0, one = -1, two = -1, maxC = 0,cone= 0, ctwo = 0 , k = 2;
        
        
        
        while(i < arr.size()){
            
            if(one == -1){
                one = arr[i];
            } else if(two == -1 && arr[i] != one){
                two = arr[i];
            }
            else if(k >= 0 && (arr[i] != one && arr[i] != two)){
                one = two;
                two = arr[i];
                cone = ctwo;
                ctwo = 0;
            }
            
            
            if(arr[i] == one){
                cone++;
            } else if(arr[i] == two){
                ctwo++;
            }
            
            maxC = max(maxC, ctwo + cone);
            i++;
        }
        
        return maxC;
    }

int main(){
    
 cout << endl;
return 0;
}