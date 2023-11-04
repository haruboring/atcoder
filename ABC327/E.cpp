#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp[0][0] = 0;

    rep(i, N) {
        rep(k, i + 1) {
            dp[k][i + 1] = max(dp[k][i + 1], dp[k][i]);

            dp[k + 1][i + 1] = max(dp[k + 1][i + 1], 0.9 * dp[k][i] + P[i]);
        }
    }

    double ans = -1e18;
    double tmp = 0;
    rep(k, N + 1) {
        rep(i, N + 1) {
            ans = max(ans, dp[k][i] / tmp - (1200 / sqrt(k)));
        }
        tmp += pow(0.9, k);
    }

    cout << fixed << setprecision(15) << ans << endl;
}