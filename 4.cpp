#include "bits/stdc++.h"
using namespace std;
using ll = long long;
string a;
ll dp[11][11][2][2][11], vis[11][11][2][2][11], vid;
ll DigitDp(int idx, int last_of_lis, bool last, bool nonzero, int Lis_Length)
{
    if (idx == a.size())
        return Lis_Length == 0;

    ll &ret = dp[idx][last_of_lis + 1][last][nonzero][Lis_Length];
    if (vis[idx][last_of_lis + 1][last][nonzero][Lis_Length] == vid)
        return ret;
    vis[idx][last_of_lis + 1][last][nonzero][Lis_Length] = vid;
    ret = 0;
    int EN = last ? 9 : a[idx] - '0';
    for (int j = 0; j <= EN; ++j)
    {
        ret += DigitDp(idx + 1, last_of_lis, j != EN || last, nonzero || j, Lis_Length);
        if (j > last_of_lis && Lis_Length && (nonzero || j))
            ret += DigitDp(idx + 1, j, j != EN || last, 1, Lis_Length - 1);
    }
    return ret;
}
void helper(int val, int m, vector<int> &lids)
{
    ++vid;
    a = to_string(val);
    for (int i = 1; i < 10; ++i)
    {
        lids[i] += DigitDp(0, -1, 0, 0, i) * m;
    }
}
pair<int, ll> solve(int s, int e)
{
    vector<int> lids(10);
    helper(e, 1, lids);
    helper(s - 1, -1, lids);
    for (int i = 9; i >= 1; --i)
    {
        if (lids[i])
            return {i, lids[i]};
    }
    return {0, 1};
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int nTests;
    scanf("%d", &nTests);
    for (int tc = 1; tc <= nTests; ++tc)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        auto ret = solve(s, e);
        printf("Case %d: %d %lld\n", tc, ret.first, ret.second);
    }
}