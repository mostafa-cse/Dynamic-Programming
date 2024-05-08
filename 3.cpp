#include <bits/stdc++.h>
using namespace std;
string X, Y;
int vis[11][2][2][11][11][2], cache[11][2][2][11][11][2], pr = 1;
int dp (int pos, bool bigX, bool smallY, int last, int lis, bool zero) {
    if (pos == Y.size()) {
        return lis == 0;
    }
    if (vis[pos][bigX][smallY][last][lis][zero] == pr) {
        return cache[pos][bigX][smallY][last][lis][zero];
    }
    vis[pos][bigX][smallY][last][lis][zero] = pr;
    int ans = 0;
    int lb = bigX ? 0 : X[pos] - '0';
    int ub = smallY ? 9 : Y[pos] - '0';
    for (int i = lb; i <= ub; i++) {
        ans += dp(pos + 1, bigX or (i > (X[pos] - '0')), smallY or (i < (Y[pos] - '0')), last, lis, zero or i);
        if (i >= last and lis > 0 and (zero or i)) {
            ans += dp(pos + 1, bigX or (i > (X[pos] - '0')), smallY or (i < Y[pos] - '0'), i + 1, lis - 1, zero or i);
        }
    }
    return cache[pos][bigX][smallY][last][lis][zero] = ans;
}
int main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        cin >> X >> Y;
        X = string(Y.size() - X.size(), '0') + X;
        for (int lis = 9; lis >= 0; lis--) {
            pr++;/*=> use this for ignore multiple time memset*/
            int ans = dp(0, 0, 0, 0, lis, 0);
            if (ans) {
                cout << lis << " " << ans << endl;
                break;
            }
        }
    }
    return 0;
}