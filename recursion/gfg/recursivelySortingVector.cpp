#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& st, int temp){

    if(st.size() == 0 || st[st.size()-1] <= temp){
        st.push_back(temp);
        return;
    }

    int val = st[st.size()-1];

    st.pop_back();

    insert(st,temp);

    st.push_back(val);
}

void sort(vector<int>& st){

    if(st.size() == 1){
        return;
    }

    int temp = st[st.size()-1];

    st.pop_back();

    sort(st);

    insert(st, temp);

}


    // T.C : O( N-1 + N*(N+1)/2) == O(N^2)
    // S.C : O(N)

int main()
{
    vector<int> arr = {4, 2, 7, 1, -1, 3};

    sort(arr);

    cout << "\nArray:\t";

    for(int ele: arr){
        cout << ele << " ";  
    }
    cout << endl;
    return 0;
}