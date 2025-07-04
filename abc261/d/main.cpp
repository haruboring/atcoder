#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<int> C(M), Y(M);
    rep(i, M) cin >> C[i] >> Y[i];

    map<int, int> m;
    rep(i, M) m[C[i]] = Y[i];

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, N) {
            if (dp[i][j] == -1) continue;

            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + m[j + 1] + X[i]);
        }
    }

    int ans = -1;
    rep(i, N + 1) ans = max(ans, dp[N][i]);
    cout << ans << endl;
}
