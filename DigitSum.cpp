#include<bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(x)
#endif
class solution {
private:
    string X, Y;
    int dp[16][2][2][15 * 9 + 1];
    int DigitDp(int idx, bool lx, bool ly, int sum) {
        if(idx == Y.size()) {
            return sum;
        }
        int &ans = dp[idx][lx][ly][sum];
        if(ans != -1) {
            return ans;
        }
        int lb = lx ? X[idx] - '0' : 0;
        int ub = ly ? Y[idx] - '0' : 9;
        ans = 0;
        for (int i = lb; i <= ub; i++) {
            ans += DigitDp(idx + 1, lx and (i == lb), ly and (i == ub), sum + i);
        }
        return ans;
    }

public:
    void solve() {
        cin >> X >> Y;
        while(X.size() != Y.size()) {
            X = '0' + X;
        }
        memset(dp, -1, sizeof(dp));
        cout << DigitDp(0, 1, 1, 0) << '\n';
    }
};
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    int tc;
    cin >> tc;
    solution obj;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case " << i << ": ";
        obj.solve();
    }
    return 0;
}
