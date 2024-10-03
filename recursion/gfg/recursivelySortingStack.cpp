#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int temp){

	if(st.empty() || st.top() <= temp){
		st.push(temp);
		return;
	}

	int val = st.top();

	st.pop();

	insert(st,temp);

	st.push(val);
}

void sortStack(stack<int>& st){

	if(st.size() == 1){
		return;
	}

	int temp = st.top();

	st.pop();
	sortStack(st);

	insert(st,temp);
}

void SortedStack :: sort()
{
    
    sortStack(s);
    
    // T.C : O( N-1 + N*(N+1)/2) == O(N^2)
    // S.C : O(N)
    
}

int main()
{
    cout << endl;
    return 0;
}