#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<int> graph[1001];
bool rec (int node, set<int> st) {
    if (st.size() == n) {
        return true;
    }
    bool res = false;
    for (auto nbr : graph[node]) {
        if (st.find(nbr) == st.end()) {
            set<int> temp = st;
            temp.insert(nbr);
            res |= rec(nbr, temp);
        }
    }
    return res;
}
map<pair<int, set<int>>, bool> dp;
bool tabu(int node, set<int> st) {
    if (st.size() == n) {
        return true;
    }
    if (dp.count({node, st})) {
        return dp.count({node, st});
    }
    bool res = false;
    for (auto nbr : graph[node]) {
        if (st.find(nbr) == st.end()) {
            set<int> temp = st;
            temp.insert(nbr);
            res |= tabu(nbr, temp);
        }
    }
    return dp[{node, st}] = res;
}
int memo[1001][1 << 20];
bool bitmaskTopDown(int node, int mask) {
    if (mask == (1 << n) - 1) {
        return true;
    }
    if (memo[node][mask] != -1) {
        return memo[node][mask];
    }
    bool res = false;
    for (auto nbr : graph[node]) {
        if (!((mask >> nbr) & 1)) {
            res |= bitmaskTopDown(nbr, mask | (1 << nbr));
        }
    } 
    return res;
}
bool bitmaskTabu() {
    int memo[n][1 << n];
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; i++) {
        memo[i][1 << i] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int node = 0; node < n; node++) {
            if (memo[node][mask]) {
                for (auto nbr : graph[node]) {
                    if (!((mask >> nbr) & 1)) {
                        memo[nbr][mask | 1 << nbr] = 1;
                    }
                }
            }
        }
    }
    bool ans = false;
    for (int node = 0; node < n; node++) {
        ans |= memo[node][(1 << n) - 1];
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool Hamiltonian = false; 
    for (int i = 0; i < n; i++) {
        set<int> st;
        st.insert(i);
        Hamiltonian |= rec(i, st);
    }
    cout << (Hamiltonian ? "Yes" : "No") << endl;
    return 0;
}
