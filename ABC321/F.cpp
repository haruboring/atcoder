#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q, K;
    cin >> Q >> K;
    vector<char> c(Q);
    vector<int> x(Q);
    rep(i, Q) cin >> c[i] >> x[i];

    int MOD = 998244353;

    vector<vector<int>> dp(Q + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < Q; ++i) {
        char c_i = c[i];
        int x_i = x[i];

        for (int j = 0; j <= K; j++) {
            dp[i + 1][j] = dp[i][j];
        }

        if (c_i == '+') {
            for (int j = 0; j <= K; ++j) {
                if (j + x_i <= K) {
                    dp[i + 1][j + x_i] += dp[i][j];
                    dp[i + 1][j + x_i] %= MOD;
                }
            }
        } else {
            for (int j = 0; j <= K; j++) {
                if (j + x_i <= K) {
                    dp[i + 1][j + x_i] += MOD - dp[i + 1][j];
                    dp[i + 1][j + x_i] %= MOD;
                }
            }
        }

        cout << dp[i + 1][K] << endl;
    }
}