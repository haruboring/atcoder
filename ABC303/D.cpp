#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    vector<vector<ll>> dp(S.size() + 1, vector<ll>(2, 0));

    if (S[0] == 'A') {
        dp[0][0] = Y;      // OFF
        dp[0][1] = Z + X;  // ON
    } else {
        dp[0][0] = X;
        dp[0][1] = Z + Y;
    }
    repp(i, 1, S.size()) {
        if (S[i] == 'A') {
            dp[i][0] = min(dp[i - 1][0] + Y, dp[i - 1][0] + Z + X + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + X + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Z + Y);

            dp[i][1] = min(dp[i - 1][0] + Y + Z, dp[i - 1][0] + Z + X);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + X);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Z + Y + Z);
        } else {
            dp[i][0] = min(dp[i - 1][0] + X, dp[i - 1][0] + Z + Y + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Y + Z);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + Z + X);

            dp[i][1] = min(dp[i - 1][0] + X + Z, dp[i - 1][0] + Z + Y);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Y);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Z + X + Z);
        }
    }
    cout << min(dp[S.size() - 1][0], dp[S.size() - 1][1]) << endl;
}