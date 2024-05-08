#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using lld = long double;

ll dp[11][2][2][11][10][2];

int rec(int pos, bool f1, bool f2, int prev, int k, string &s1, string &s2, int start, bool f3)
{

    if (pos == (int)s1.size())
    {
        return k == 0;
    }

    if (dp[pos][f1][f2][prev][k][f3] != -1)
        return dp[pos][f1][f2][prev][k][f3];

    int mn, mx;
    mn = f1 ? 0 : s1[pos] - '0';
    mx = f2 ? 9 : s2[pos] - '0';

    ll res = 0;
    for (int i = mn; i <= mx; i++)
    {
        bool nf1 = f1;
        bool nf2 = f2;
        bool nf3 = f3;

        if (i > mn)
            nf1 = 1;
        if (i < mx)
            nf2 = 1;
        if (i != 0 || pos >= start)
            nf3 = 1;

        // don't take
        res += rec(pos + 1, nf1, nf2, prev, k, s1, s2, start, nf3);
        // take
        if (i >= prev && nf3)
        {
            res += rec(pos + 1, nf1, nf2, i + 1, k - 1, s1, s2, start, nf3);
        }
    }

    return dp[pos][f1][f2][prev][k][f3] = res;
}

void solve(int tc)
{
    ll x, y;
    cin >> x >> y;

    string s1, s2;
    s1 = to_string(x);
    s2 = to_string(y);

    int start = 0;

    while (s1.size() < s2.size())
    {
        s1 = "0" + s1;
        start++;
    }

    int mx = 0;
    ll cnt = 0;
    for (int k = s2.size(); k > 0; k--)
    {
        memset(dp, -1, sizeof dp);
        ll curr = rec(0, 0, 0, 0, k, s1, s2, start, 0);
        if (curr)
        {
            mx = k;
            cnt = curr;
            break;
        }
    }
    cout << "Case " << tc << ": " << mx << " " << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        solve(tc);
    }
}