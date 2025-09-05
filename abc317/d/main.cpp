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
    vector<int> X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

    vector<vector<int>> dp(N + 1, vector<int>(1e5 + 10, 1e18));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, 1e5) {
            if (dp[i][j] == 1e18) continue;
            int half = (X[i] + Y[i] + 1) / 2;
            int ex = max(0LL, half - X[i]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + Z[i]] = min(dp[i + 1][j + Z[i]], dp[i][j] + ex);
        }
    }

    int zs = accumulate(all(Z), 0LL);

    int ans = 1e18;
    repp(i, zs / 2 + 1, zs + 1) ans = min(ans, dp[N][i]);
    cout << ans << endl;
}
