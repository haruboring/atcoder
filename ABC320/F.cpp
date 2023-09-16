#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, H;
    cin >> N >> H;
    vector<int> X(N + 1);
    X[0] = 0;
    rep(i, N) {
        cin >> X[i + 1];
    }
    vector<int> P(N - 1), F(N - 1);
    rep(i, N - 1) {
        cin >> P[i] >> F[i];
    }

    // 往路の最小コスト
    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 1e18));
    dp[0][H] = 0;

    rep(i, N) {
        rep(j, H + 1) {
            if (dp[i][j] == 1e18) continue;
            if (j - (X[i + 1] - X[i]) < 0) continue;
            dp[i + 1][j - (X[i + 1] - X[i])] = min(dp[i + 1][j - (X[i + 1] - X[i])], dp[i][j]);

            if (i == N - 1) continue;
            dp[i + 1][min(H, j - (X[i + 1] - X[i]) + F[i])] = min(dp[i + 1][min(H, j - (X[i + 1] - X[i]) + F[i])], dp[i][j] + P[i]);
        }
    }

    // 復路の最小コスト
    vector<int> Y(N + 1);

    rep(i, N + 1) Y[i] = X[N] - X[i];
    sort(all(Y));

    reverse(all(F));
    reverse(all(P));

    int ans = 1e18;
    rep(h, H + 1) {
        if (dp[N][h] == 1e18) continue;

        vector<vector<int>> dp2(N + 1, vector<int>(H + 1, 1e18));
        dp2[0][h] = dp[N][h];
        rep(i, N) {
            rep(j, H + 1) {
                if (dp2[i][j] == 1e18) continue;
                if (j - (Y[i + 1] - Y[i]) < 0) continue;
                dp2[i + 1][j - (Y[i + 1] - Y[i])] = min(dp2[i + 1][j - (Y[i + 1] - Y[i])], dp2[i][j]);

                if (i == N - 1) continue;
                dp2[i + 1][min(H, j - (Y[i + 1] - Y[i]) + F[i])] = min(dp2[i + 1][min(H, j - (Y[i + 1] - Y[i]) + F[i])], dp2[i][j] + P[i]);
            }
        }
        rep(i, H + 1) {
            ans = min(ans, dp2[N][i]);
        }
    }

    if (ans == 1e18) ans = -1;
    cout << ans << endl;
}