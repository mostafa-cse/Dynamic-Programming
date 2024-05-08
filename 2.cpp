#include <bits/stdc++.h>
using namespace std;
string X, Y;
pair<int, int> dp[16][16][2][2];
pair<int, int> DigitDp(int idx, int l, bool lx, bool ly, bool p0) {
    if(idx == X.size()) {
        return {0, 1};
    }
    if(dp[idx][l + 1][lx][ly].first != -1) {
        return dp[idx][l + 1][lx][ly];
    }
    int lb = ((lx) ? X[idx] - '0' : 0);
    int ub = ((ly) ? Y[idx] - '0' : 9);
    pair<int, int> res = {0, 0};
    for (int i = lb; i <= ub; i++) {
        pair<int, int> a = DigitDp(idx + 1, l, (lx and (i == lb)), (ly and (i == ub)), (p0 and (i == 0)));
        if (res.first < a.first) {
            res = a;
        } else if(res.first == a.first){
            res.second += a.second;
        }
        if (i > l and !(p0 and (i == 0))) {
            a = DigitDp(idx + 1, i, (lx and (i == lb)), (ly and (i == ub)), 0);
            a.first++; /*why => i don't know but it works for correct ans*/
            if (res.first < a.first) {
                res = a;
            } else if(res.first == a.first){
                res.second += a.second;
            }
        }
    }
    return dp[idx][l + 1][lx][ly] = res;
}
int main() {
    int tc; 
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        cin >> X >> Y;
        while (X.size() != Y.size()) {
            X = '0' + X;
        }
        memset(dp, -1, sizeof(dp));
        auto [a, b] = DigitDp(0, -1, 1, 1, 1);
        cout << a << " " << b << endl;
    }
    return 0;
}
