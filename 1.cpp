#include <bits/stdc++.h>
using namespace std;
int dp[11][2][2][11][2][11], n;
string str1, str2;
int solve(int idx, bool LastY, bool LastX, int lids_value, bool start, int len)
{
    if (idx == n)
    {
        return len == 0;
    }
    int &res = dp[idx][LastY][LastX][lids_value][start][len];
    if (res != -1)
        return res;
    int ub = LastY ? (str2[idx] - '0') : 9;
    int lb = LastX ? (str1[idx] - '0') : 0;
    res = 0;
    for (int i = lb; i <= ub; i++)
    {
        if (((i > lids_value && start) || (start == false && i != 0)) && len > 0)
        {
            res += solve(idx + 1, (LastY & (i == ub)), (LastX & (i == lb)), i, (start | (i != 0)), len - 1);
        }
        res += solve(idx + 1, (LastY & (i == ub)), (LastX & (i == lb)), lids_value, (start | (i != 0)), len);
    }

    return res;
}

signed main()
{

    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        memset(dp, -1, sizeof dp);
        cin >> str1 >> str2;
        while (str1.length() != str2.length()) {
            str1  = '0' + str1;
        }
        n = str1.size();
        for (int lids = 9; lids >= 1; lids--)
        {
            int temp = solve(0, 1, 1, -1, 0, lids);
            if (temp != 0) {
                cout << "Case " << test << ": " << lids << " " << temp << '\n';
                break;
            }
        }
    }

    return 0;
}
