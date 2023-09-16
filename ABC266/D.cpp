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
    vector<int> T(N), X(N), A(N);
    rep(i, N) cin >> T[i] >> X[i] >> A[i];
    map<int, pair<int, int>> mp;
    rep(i, N) mp[T[i]] = make_pair(X[i], A[i]);

    vector<vector<int>> dp(1e5 + 1, vector<int>(5, -1));
    dp[0][0] = 0;

    rep(i, 1e5 + 1) {
        if (mp.find(i) != mp.end()) {
            auto [x, a] = mp[i];
            if (dp[i][x] != -1) {
                dp[i][x] += a;
            }
        }
        if (i == 1e5) continue;
        rep(j, 5) {
            if (dp[i][j] == -1) continue;
            if (j == 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            } else if (j == 4) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
            } else {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
            }
        }
    }

    int ans = 0;
    rep(i, 5) {
        ans = max(ans, dp[1e5][i]);
    }

    cout << ans << endl;
}