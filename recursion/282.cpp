




#include<bits/stdc++.h>
using namespace std;

 void sol(int i, vector<string>& ans, int& target, string& num, string str, long prev, long calculatedValue);

void solve(string num, int i, long value, long prev, string curr, int target, vector<string>& ans){
        // Base Case
        if(i == num.size()){
            if(value == target) ans.push_back(curr);
            return;
        }

        for(int j = i; j<num.size(); j++){
            // Prevent leading zero
            if(j != i && num[i] == '0') break;

            string part = num.substr(i, j - i + 1);
            long currVal = stol(part);

            // Initial condition
            if(i == 0) solve(num, j+1, currVal, currVal, part, target, ans);    
            else{
                // Addition
                solve(num, j+1, value + currVal, currVal, curr + "+" + part, target, ans);
                
                // Subtraction
                solve(num, j+1, value - currVal, -currVal, curr + "-" + part, target, ans);
                
                // Multiplication
                solve(num, j+1, value - prev + (prev * currVal), prev * currVal, curr + "*" + part, target, ans);
            }
        }
    }

int main()
{

    vector<string> ans;
        solve(num, 0, 0, 0, "", target, ans);
        // return ans;
    cout << endl;
    return 0;
}



    void sol(int i, vector<string>& ans, int& target, string& num, string str, long prev, long calculatedValue){

        if(i == num.length()){

            if(calculatedValue == target){
                ans.emplace_back(str);
            }
            return;
        }

        while(i < num.length() && num[i] == '0'){ // ignoring the leading zeros
            i++;
        }


       
        for(int j = i; j < num.length(); j++){

            string part = num.substr(i,j-i+1);
            long currValue = stol(part);

            if(i == 0){
                sol(j+1, ans, target, num, part, currValue, currValue);
            } else {
                // Addition
                sol(j + 1, ans , target, num, str + "+" + part, currValue, currValue + calculatedValue);

                // Substraction
                sol(j + 1, ans, target, num, str + "-" + part, -currValue, calculatedValue - currValue);

                // Multiplication
                sol(j + 1, ans, target, num, str + "*" + part, prev * currValue, calculatedValue - prev +  (prev*currValue));
            }
        }
    }
