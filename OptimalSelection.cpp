#include <bits/stdc++.h>
using namespace std;
int k, n, price[1001][1001];
long long int dp[1001][1 << 10];
int main() {
    cin >> k >> n;
    for (int products = 0; products < k; products++) {
        for (int days = 0; days < n; days++) {
            dp[products][days] = 1e9;
            cin >> price[products][days];
        }
    }
    dp[0][0] = 0;
    for (int  i = 0; i < k; i++) {
        dp[1 << i][0] = price[i][0];
    }
    for (int mask = 0; mask < (1 << k); mask++) {
        for (int day = 1; day < n; day++) {
            dp[mask][day] = dp[mask][day - 1]; /*don't buy anything on this day*/
            for (int product = 0; product < k; product++) {
                if ((mask >> product) & 1) {
                    dp[mask][day] = min(dp[mask][day], /*don't buy result*/
                                        dp[mask ^ (1 << product)][day - 1] + price[product][day]/*buy this day */
                                    );
                }
            }
        }
    }
    cout << dp[(1 << k) - 1][n - 1] << '\n';
    return 0;
}