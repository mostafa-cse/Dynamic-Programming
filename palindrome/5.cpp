#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[20][20][2][2][2];
int DigitDp(int l, int r, bool ll, bool rr, bool start, string num) {
    if(l > r) {
        return ll >= rr;
    }

    int &res = dp[l][r][ll][rr][start] ;
    if (res != -1) {
        return res;
    }

    int range = ll ? 9 : (num[l] - '0');
    res = 0;
    for (int i = 0; i <= range; i++) {
        int new_st = (start or i > 0);
        int n_ll = ll;
        if (i < range) {
            n_ll = 1;
        }
        int n_rr = rr;
        n_rr = (n_ll or i < (num[r] - '0') ? 0 : rr or (i > (num[r] - '0')));

        if(new_st) {
            res += DigitDp(l + 1, r - 1, n_ll, n_rr, 1, num);
        } else {
            res += DigitDp(l + 1, r - 1, n_ll, n_rr, 0, num);
        }
    }
    return res;
}
int solve(int num) {
    if (num <= 9) {
        return max(0ll, num + 1);
    }
    memset(dp, -1, sizeof(dp));
    string numStr = to_string(num);
    return DigitDp(0, numStr.size() - 1, 0, 0, 0, numStr);
}
int32_t main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int a ,b;
        cin >> a >> b;
        if(a > b) {
            swap(a, b);
        }
        cout << "Case " << i << ": " << solve(b) - solve(a - 1) << '\n';
    }
    return 0;
}