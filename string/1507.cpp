
#include<bits/stdc++.h>
using namespace std;

string reformatDate(string date)
{
    vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int n = date.size();
    string ans = "";
    string s = "";
    s += date.substr(n - 4); // getting the year
    ans += s + '-';
    s = "";
    for (auto it : date) //getting the month
    {
        if (isalpha(it)) // isAlpha a function which checks for alphabetical characters is present in the string or not.
            s += it;
    }

    s = s.substr(2);
    int mon = 1;
    for (auto it : month)
    {
        if (s != it)
            mon++;
        else
            break;
    }

    // getting the date
    if (mon / 10 == 0)
        ans += '0';
    ans += to_string(mon) + '-';
    s = "";
    for (auto it : date)
    {
        if (isalpha(it))
            break;
        else
            s += it;
    }

    // cout << s << endl;
    if (s.size() == 1)
        ans += '0';
    ans += s;

    return ans;
}

int main()
{

    string str = "26th May 1960";

cout << "\n ANS: ";
    cout << reformatDate(str) << endl;
 
    
    cout << endl;
    return 0;
}
    