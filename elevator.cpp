#include <bits/stdc++.h>
using namespace std;
int main() {
    int peopele, Weight;
    cin >> peopele >> Weight;
    int w[peopele + 1];
    for (int i = 0; i < peopele; i++) {
        cin >> w[i];
    }
    pair<int, int> dp[1 << peopele];
    memset(dp, 0, sizeof(dp));
    dp[0] = {1, 0};
    for (int mask = 1; mask <(1 <<  peopele); mask++) {
        dp[mask] = {peopele, 0};
        for (int j = 0; j < peopele; j++) {
            if ((mask >> j) & 1) {
                int newmask = mask ^ (1 << j);
                pair<int, int> prev_ride =  dp[newmask];
                /*include */
                if (prev_ride.second + w[j] <= Weight) {
                    prev_ride.second += w[j];
                    prev_ride.first = prev_ride.first;
                }
                /*exclude */
                else {
                    prev_ride.first += 1;
                    prev_ride.second = w[j];
                }
                dp[mask] = min(dp[mask], prev_ride);
            }
        }
    }
    cout << dp[(1 << peopele) - 1].first << " " << dp[(1 << peopele) - 1].second << endl;
    return 0;
}