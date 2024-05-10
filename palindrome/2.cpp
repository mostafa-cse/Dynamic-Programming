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
    vector<int> num;
    int a, b, n, dp[20][20][2][2][2];
    void gen (int X) {
        num.clear();
        memset(dp, -1, sizeof(dp));
        while (X) {
            num.push_back(X % 10);
            X /= 10;
        }
        reverse(num.begin(), num.end());
        n = num.size();
    } 
    int calc (int pos, bool bound, bool nonzero, int backpos, bool greater) {
        if (pos > backpos) {
            if (!bound and greater) {
                return 0;
            } 
            return 1;
        }
        int &res = dp[pos][backpos][bound][nonzero][greater];
        if (res != -1) {
            return res;
        }
        
        res = 0;
        int range = bound ? 9 : num[pos];
        for (int i = 0; i <= range; i++) {
            if (!nonzero and i == 0) {
                res += calc(pos + 1, bound or i < range, 0, backpos, greater);
            } else if (pos == backpos){
                res += calc(pos + 1, bound or i < range, nonzero or i, backpos, greater);
            } else {
                if (i == num[backpos]) {
                    res += calc(pos + 1, bound or i < range, nonzero or i, backpos - 1, greater);
                } else {
                    res += calc(pos + 1, bound or i < range, nonzero or i, backpos - 1, i > num[backpos]);
                }
            }
        }
        return res;
    }
public:
    void solve() {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        gen(b);
        int ans = calc(0, 0, 0, n - 1, 0);
        gen(a - 1);
        ans -= calc(0, 0, 0, n - 1, 0);
        cout << ans << endl;
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