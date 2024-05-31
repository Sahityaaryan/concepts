#include<bits/stdc++.h>
using namespace std;

    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int>m;
        for(auto c: s) m[c]++;

        auto comp = [](pair<int, char>& a, pair<int, char>& b){ return a.first < b.first; }; // lambda function: ascending order

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)>pq(comp);
        for(auto x: m) pq.push({x.second, x.first});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            while(p.first--) res += p.second;
        }
        return res;
    }

void test2(){
    function<bool()> cmp = []() mutable -> bool{
        return true;
    };

    cout << "test2: " << typeid(decltype(cmp)).name() << endl; 

    // priority_queue<int, vector<int>, true>pq(true);
}

    string frequencySortByMapAndVector(string s) {
        string ans;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>>temp;
        for(auto it:mpp){
            temp.push_back(make_pair(it.first,it.second));
        }
        sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;});
        for(auto it:temp){
            for(int i=0;i<it.second;i++){
                ans.insert(ans.begin()+0,it.first);
            }
        }
        return ans;

    }
    
void test(){
    priority_queue<int , vector<int> , greater<int>> pq; // min heap

    // lambda functions
    int num = 100;
    int num1 = 12;
    int num3 = 13;
    string hail = "jai mata di";

    // _----------capture closure = []

    // capture by value : we can't modify the capture variable if it is call by value

    auto lambda = [num](){
        cout << "num " << num;
    };



    // capture by reference : we can modify here

    auto lamda2 = [&num](){
        num = 12;
        cout << "num(lamda2) " << num;
    };

    lambda();
    cout << "\n";

    lamda2();


    // all the variables of the enclosing function are captured

    auto lamda3 = [=](){
        cout << num << ' ' << num1 << ' ' << num3 << ' ' << hail << endl; 
    };

    int num44 = 7;

    // all the variables as call by reference

    function<void(int)> lamda4 = [&](int a){
        cout << " a(lamda4): " << a << endl;
    };

    cout << '\n';

    lamda3();

    cout << '\n';

    lamda4(5);

    // extended lambda function

    function<int()> lamda5 = []() -> int {
            return 2;
    };

    cout << "lamda5 " << lamda5();

}

int main()
{
 test2();
    
    cout << endl;
    return 0;
}