#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//*by me
int findJudge(int n, vector<vector<int>> &trust)
{

    if (trust.empty() && n == 1)
        return 1;

    if (trust.empty() && (n == 0 || n > 1))
        return -1;

    unordered_map<int, int> m;

    vector<bool> r(n + 1, false);
    int p = trust.size();

    int i = 0, judge = -1;

    while (i < p)
    {
        r[trust[i++][0]] = true;
    }

    for (auto x : trust)
    {
        m[x[1]]++;

        if (m[x[1]] == n - 1 && !r[x[1]])
        {
            judge = x[1];
            break;
        }
    }

    return judge;
}

//*sir

int findJudge(int n, vector<vector<int>> &trust)
{

    if (trust.empty() && n == 1)
        return 1;

    if (trust.empty() && (n == 0 || n > 1))
        return -1;

    // this can be solved by checking the number of indegree and the outdegree of the peoples as well

    vector<int> degree(n + 1, 0);

    for (auto x : trust)
    {
        degree[x[0]]--;
        degree[x[1]]++;
    }

    int i = 0, k = degree.size();

    while (i <= n)
    {
        if (degree[i] == n - 1)
            return i;
        i++;
    }

    return -1;
}

int main(){
    
    cout << endl;
    return 0;
}