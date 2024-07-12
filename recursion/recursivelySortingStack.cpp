#include <bits/stdc++.h>
using namespace std;

void recursionSorting(stack<int> &st, int n)
{

    if (st.empty())
    {
        st.push(n);
        return;
    }

    int k = st.top();

    st.pop();

    recursionSorting(st, k);

    if (n != -1)
    {

        if (st.top() <= n)
        {
            st.push(n);
        }
        else
        {

            stack<int> s;

            while (!st.empty() && st.top() > n)
            {
                s.push(st.top());
                st.pop();
            }

            st.push(n);

            while (!s.empty())
            {
                st.push(s.top());
                s.pop();
            }
        }
    }
}

int main()
{
    cout << endl;
    return 0;
}