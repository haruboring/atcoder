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
    vector<int> X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

    int ans = -1e18;

    rep(k, 8) {
        int tmp = k;
        int a = 1, b = 1, c = 1;
        if (tmp % 2) a = -1;
        tmp /= 2;
        if (tmp % 2) b = -1;
        tmp /= 2;
        if (tmp % 2) c = -1;
        // cout << a << " " << b << " " << c << endl;

        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1e18));
        dp[0][0] = 0;
        rep(i, M) {
            rep(j, N) {
                if (dp[i][j] == -1e18) continue;
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a * X[j] + b * Y[j] + c * Z[j]);
            }
        }
        rep(i, N + 1) {
            ans = max(ans, dp[M][i]);
        }
        // debug(ans);
    }
    cout << ans << endl;
}
