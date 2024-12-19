#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {

        // here in this solution I am strictly abiding by the constraints of the position that the '(' should always be
        // before the ')' and the '*' can take any of the possible values so we also have to mind the position of '*'
        // that whether '*' can be converted into a parenthesis on the basis of positions

        // optimization time

        stack<pair<char, int>> st1;
        stack<pair<char, int>> st2;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == ')'){
                if(!st1.empty()){
                    st1.pop();
                } else if(!st2.empty()){
                    st2.pop();
                } else return false;

            } else if(s[i] == '('){
                st1.push({s[i], i});
            } else {
                st2.push({s[i], i});
            }

        }


        while(!st1.empty() ){

            int pos1 = st1.top().second;
            int pos2;
           if(!st2.empty()) pos2 = st2.top().second;
           else return false;

            if(pos2 > pos1){
                st1.pop();st2.pop();
            } else return false;
        }



        return st1.empty();
    }


    // the below is approach is more space efficient then the above one but it is not checking the time
    // it is checking the range of possibility

    // What's the reason of the possibility case?
    // The reason is asterisk it can act both kind of parenthesis and hence there is two possibility of parenthesis situation
    //

    // why are we checking only minimum open parenthesis?
    // Because it is showing a possibility when all the asterisk are correctly changed then how many parenthesis will remain open
    // which we want and we are checking for the high as well because there may situation when the ')' becomes more so for that we
    // are having an eye over maximum_open_parenthesis

bool checkValidString2(string s) {
    int minimum_open_parenthesis = 0, maximum_open_parenthesis = 0; // Range of possible open parentheses

    for (char c : s) {
        if (c == '(') {
            minimum_open_parenthesis++;
            maximum_open_parenthesis++;
        } else if (c == ')') {
            if (minimum_open_parenthesis > 0) minimum_open_parenthesis--; // Decrease minimum open parentheses
            maximum_open_parenthesis--; // Decrease maximum open parentheses
        } else if (c == '*') {
            if (minimum_open_parenthesis > 0) minimum_open_parenthesis--; // '*' can act as ')'
            maximum_open_parenthesis++; // '*' can act as '('
        }

        if (maximum_open_parenthesis < 0) return false; // Too many ')'
    }

    return minimum_open_parenthesis == 0; // All open parentheses must be matched
}



int main(){

    return 0;
}
