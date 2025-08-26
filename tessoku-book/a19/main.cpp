#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vector<vector<int>> dp(N + 1, vector<int>(100001, -1));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, W + 1) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] > W) continue;
            dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
        }
    }
    int ans = -1;
    rep(i, W + 1) ans = max(ans, dp[N][i]);
    cout << ans << endl;
}
