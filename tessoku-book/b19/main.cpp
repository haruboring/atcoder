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

    vector<vector<int>> dp(N + 1, vector<int>(100000 + 10000, 1e18));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, 100000 + 10) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
        }
    }

    int ans = -1;
    rep(i, 100000 + 10) if (dp[N][i] <= W) ans = i;
    cout << ans << endl;
}
