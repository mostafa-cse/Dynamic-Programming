#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; i++)
ll dp[20][20][2][2], d[20], cnt;
ll DigitDp (int bg, int l, int r, int tag, bool ok) {
    if (r > l) {
        return !tag or (tag and ok);
    }
    if(!tag and dp[bg][l][tag][ok]) {
        return dp[bg][l][tag][ok];
    }
    int lim = tag ? d[l] : 9;
    ll res = 0;
    rep(i, 0, lim) {
        if (bg == l and i == 0) {
            continue;
        }

        bool g = ok;
        if (ok) {
            g = (i <= d[r]);
        } else {
            g = (i < d[r]);
        }
        res += DigitDp(bg, l - 1, r + 1, tag and (i == lim), g);
    }
    return (tag ? res : (dp[bg][l][tag][ok] = res));
}
ll call(ll x) {
    if(x <= 9) {
        return max(0ll, x + 1);
    }
    ll res = 1;
    cnt = 0;
    while (x) {
        d[++cnt] = x % 10;
        x /= 10;
    }    
    memset(dp, 0, sizeof dp);
    rep(i, 1, cnt) {
        res += DigitDp(i, i, 1, i == cnt, true);
    }
    return res;
}
int main() {
    int tc; 
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        ll a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        cout << call(b) - call(a - 1) << '\n';
    }
    return 0;
}