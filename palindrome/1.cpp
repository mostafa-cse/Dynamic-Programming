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
    int a, b, dp[20][20];
    vector<int> num;
    int DigitDp (int idx, int len, bool zero, int ta, vector<int>&ck) {
        if (idx <= 0) {
            return zero;
        }

        int &res = dp[idx][len];
        if (!ta and res != -1) {
            return res;
        }

        res = 0;
        int range = ta ? num[idx - 1] : 9;
        for (int i = 0; i <= range; i++) {
            if (!zero) {
                res += DigitDp(idx - 1, len - (!i), zero or i, ta and (i == range), ck);
            } else {
                int m = len / 2;
                if (idx <= m) {
                    if (i == num[len - idx]) {
                        res += DigitDp(idx - 1, len, 1, ta and (i == range), ck);
                    }
                } else {
                    res += DigitDp(idx - 1, len, 1, ta and (i == range), ck);
                }
            }
        }
        return res;
    }
    int calc (int X) {
        if (X <= 0) {
            return X;
        }
        num.clear();
        while (X) {
            num.push_back(X % 10);
            X /= 10;
        }
        memset(dp , -1, sizeof dp);
        vector<int>check;
        return DigitDp(num.size(), num.size(), 0, 1, check);
    }
public:
    void solve() {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        cout << calc(b) - calc(a - 1ll) << endl;
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