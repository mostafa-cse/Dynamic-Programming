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
    int a, b, dp[20][20][2][2][2];
    string s;
    int DigitDp (int l ,int r, bool is_low_left, bool is_high_right, bool lz) {
        if (l > r) {
            return is_low_left or !is_high_right;
        }
        int &res = dp[l][r][is_low_left][is_high_right][lz];
        if (res != -1) {
            return res;
        }

        res = 0;
        int range = is_low_left ? 9 : s[l] - '0';
        for (int d = 0; d <= range; d++) {
            bool NotZero = lz and !d;
            bool nis_low_left = is_low_left or (s[l] - '0' > d);
            bool nis_high_left = (d == s[r] - '0' ? is_high_right : d > s[r] - '0');
            res += DigitDp(l + 1, r - !NotZero, nis_low_left, nis_high_left, NotZero);
        }
        return res;     
    }
    int calc(int X) {
        s = to_string(X);
        memset(&dp, -1, sizeof(dp));
        return DigitDp(0, s.size() - 1, false, false, true);
    }
public:
    void solve() {
        cin >> a >> b;
        if(a > b) {
            swap(a, b);
        }
        cout << calc(b) - calc(a - 1) << '\n';
    }
};
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    int tc;
    cin >> tc;
    solution obj;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        obj.solve();
    }
    return 0;
}