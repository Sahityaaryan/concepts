#include<bits/stdc++.h>
using namespace std;
 

  bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false; // can't be arranged in a group
        int gs = groupSize;

        unordered_map<int , int> mp1;
        map<int , int> mp2;

        for(int &it:hand){
            mp2[it]++;
        }
        int i = 1;

        auto it = mp2.begin();
        it++;
        while(!mp2.empty()){

            while(i < gs && it != mp2.end()){
                if(it->first > (--it)->first+1 && i < gs){
                    return false;
                }
                it++;

                it->second--;
                
                if(it->second <= 0){
                    it = mp2.erase(it);
                } else it++;

                i++;
            }

            if(i < gs && mp2.empty()){
                return false;
            }

            i = 0;
        }


        return true;
    }


int main(){
    
 cout << endl;
return 0;
}