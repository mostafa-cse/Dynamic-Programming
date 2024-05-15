#include <bits/stdc++.h>
using namespace std;
int N, u, v, dp[100001][2];
vector<int> tree[100001];
int rec(int node, int take, int parent) {
    if (dp[node][take] != -1) {
        return dp[node][take];
    }
    int res = take;
    for (auto nbr : tree[node]) {
        if (nbr != parent) {
            if (take) {
                res += min(rec(nbr, 1, node), rec(nbr, 0, node));
            } else {
                res += rec(nbr, 1, node);
            }
        }
    }
    return dp[node][take] = res;
}
int32_t main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    cout << min(rec(1, 0, -1), rec(1, 1, -1)) << '\n';
    return 0;
}
