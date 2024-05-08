#include <bits/stdc++.h>
#define int long long
using namespace std;
string X, Y;
int res, dp[11][2][2][11][11];
int DigitDp(int pos, bool low, bool st, int curr, int lis, string &Str) {
    if(pos >= Str.size() or lis < 0) {
        return lis == 0;
    }
    if (dp[pos][low][st][curr][lis] != -1) {
        return dp[pos][low][st][curr][lis];
    }
    int ans = 0;
    int limit = low ? 10 : (Str[pos] - '0' + 1);
    for (int i = 1; i <= limit; i++) {
        if (!st and (i == 1)) {
            ans += DigitDp(pos + 1, low or (i < limit), st || (i - 1), curr, lis, Str);
        } else {
            if (i <= curr) {
                ans += DigitDp(pos + 1, low or (i < limit), st or (i - 1), curr, lis, Str);
            } else if (i > curr) {
                ans += DigitDp(pos + 1, low or (i < limit), st or (i - 1), i, lis - 1, Str) +
                       DigitDp(pos + 1, low or (i < limit), st or (i - 1), curr, lis, Str);
            }
        }
    }
    return dp[pos][low][st][curr][lis] = ans;
}
int32_t main() {
    int tc;
    cin >> tc;
    for (int testcase = 1; testcase <= tc; testcase++) {
        cout << "Case " << testcase << ": ";
        cin >> X >> Y;
        int j = X.size() - 1;
        while (j >= 0 and X[j] == '0')
        {
            X[j] = '9';
            j -= 1;
        }
        X[j] = X[j] - 1;
        bool ok = true;
        for (int lis = Y.size(); lis >= 0; lis--)
        {
            memset(&dp, -1, sizeof dp);
            int x = DigitDp(0, 0, 0, 0, lis, X);
            memset(&dp, -1, sizeof dp);
            int y = DigitDp(0, 0, 0, 0, lis, Y);
            if ((res = y - x) > 0)
            {
                ok = false;
                cout << lis << " " << res << endl;
                break;
            }
        }
        if(ok) {
            cout << 0 << " " << 0 << '\n';
        }
    }
    return 0;
}