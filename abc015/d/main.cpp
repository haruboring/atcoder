#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W;
    cin >> W;
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(W + 1, vector<int>(K + 1)));
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, W + 1) {
            rep(k, K + 1) {
                if (dp[i][j][k] == -1) continue;
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                if ((j + A[i] > W) || (k + 1 > K)) continue;
                dp[i + 1][j + A[i]][k + 1] = max(dp[i + 1][j + A[i]][k + 1], dp[i][j][k] + B[i]);
            }
        }
    }

    int ans = 0;
    rep(i, N + 1) rep(j, W + 1) rep(k, K + 1) ans = max(ans, dp[i][j][k]);

    cout << ans << endl;
}
