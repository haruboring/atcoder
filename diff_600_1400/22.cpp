#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll MOD = 998244353;

    vector<vector<ll>> dp(K + 1, vector<ll>(4));
    dp[0][0] = ((x1 == x2) && (y1 == y2));  // (x2, y2)
    dp[0][1] = ((x1 == x2) && (y1 != y2));  // (x2, !=y2)
    dp[0][2] = ((x1 != x2) && (y1 == y2));  // (!x2, y2)
    dp[0][3] = ((x1 != x2) && (y1 != y2));  // (!x2, !=y2)

    repp(i, 1, K + 1) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] * (W - 1) + dp[i - 1][1] * (W - 2) + dp[i - 1][3];
        dp[i][2] = dp[i - 1][0] * (H - 1) + dp[i - 1][2] * (H - 2) + dp[i - 1][3];
        dp[i][3] = dp[i - 1][1] * (H - 1) + dp[i - 1][2] * (W - 1) + dp[i - 1][3] * (W + H - 4);

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
    }

    cout << dp[K][0] << endl;
}