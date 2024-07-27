#include <bits/stdc++.h>
using namespace std;


// it is not done till so far:

bool check(string s, int leader, int lagger)
{

    while (leader > lagger)
    {
        if (s[leader] != s[lagger])
        {
            return false;
        }
        leader--;
        lagger++;
    }

    return true;
}

void sol(vector<vector<string>> &ans, string s, int window)
{

    if (window > s.length())
    {
        return;
    }


    int lagger = 0, outerLagger = 0;
    int leader = lagger + window - 1;
    bool flag = false;
    int lastLeader = 0, lastLagger = 0;

    while (outerLagger <= s.length() - window)
    {
        vector<string> ansString;

        leader = outerLagger + window - 1;
        lagger = outerLagger;

        cout << "leader  " << leader << " outerLagger: " << lagger << endl;

        while (leader < s.length())
        {

            // cout << "leader: " << leader << " lagger: " << lagger << '\n';

            if (s[leader] == s[lagger] && check(s, leader, lagger))
            {

                if (!flag)
                {
                    string remaingingLaggerString = s.substr(0, lagger);
                    // cout <<  "remaingingLaggerString: " << remaingingLaggerString << endl;
                    if (remaingingLaggerString != "")
                    {
                        ansString.emplace_back(remaingingLaggerString);
                    }
                }

                ansString.emplace_back(s.substr(lagger, window));
                flag = true;
                lastLeader = leader;
                lagger = leader + 1;
                leader = lagger + window - 1;

                if (leader >= s.length())
                {
                    leader = s.length() - 1;
                }
            }
            else
            {
                leader++;
                lagger++;
            }
        }
        outerLagger++;
        string remainingString = s.substr(lastLeader + 1, window);

        if (flag && remainingString != "")
        {
            ansString.emplace_back(remainingString);
        }

        if (!ansString.empty())
        {
            ans.emplace_back(ansString);
        }
    }

    sol(ans, s, window + 1);
}

vector<vector<string>> partition(string s)
{

    // by Brute force it is going upto the T.C : O((N^3 -3(N^2) + 2N) / 2);
    // I can ease it by one multiple of N by using recursion to involve one level of iteration in the recursion stack
    vector<vector<string>> ans;

    sol(ans, s, 1);

    return ans;
}

int main()
{
    string s = "fff";

    vector<vector<string>> ans = partition(s);

    for (auto it : ans)
    {

        cout << "[ ";
        for (string s : it)
        {
            cout << s << ' ';
        }

        cout << "]\n";
    }

    cout << endl;
    return 0;
}
