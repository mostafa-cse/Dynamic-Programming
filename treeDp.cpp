#include <bits/stdc++.h>
using namespace std;

int arr[6005], dp[6005][2]; // 0-not choose, 1-choose
vector<int> tree[6005];
bool isroot[6005];
int l, k, n, root;

void solve(int root)
{
    dp[root][0] = 0;
    dp[root][1] = arr[root];
    for (auto child :  tree[root]) {
        if (dp[child][0] == -1) {
            solve(child);
        }
    }
    for (auto child : tree[root]) {
        dp[root][0] += max(dp[child][0], dp[child][1]);
        dp[root][1] += dp[child][0];
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(isroot, true, sizeof isroot);
        tree->clear();
        for (int i = 1; i <= n; i++) {
            scanf_s("%d", &arr[i]);
        }

        while (scanf("%d%d", &l, &k) && l) {
            tree[k].push_back(l);
            isroot[l] = false;
        }

        for (int i = 1; i <= n; i++) {
            if (isroot[i]) {
                root = i;
                break;
            }
        }
        memset(dp, -1, sizeof dp);
        solve(root);
        printf("%d\n", max(dp[root][0], dp[root][1]));
    }
}
