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
    vector<int> P(N + 1), A(N + 1);
    rep(i, N) cin >> P[i + 1] >> A[i + 1];

    map<int, int> m;
    rep(i, N) m[P[i]] += A[i];

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[1][N] = 0;
    for (int len = N - 2; len >= 0; len--) {
        for (int r = 1; r + len <= N; r++) {
            if (r - 1 >= 1) dp[r][r + len] = max(dp[r][r + len], dp[r - 1][r + len] + A[r - 1] * (P[r - 1] >= r && P[r - 1] <= r + len));
            if (r + len + 1 <= N) dp[r][r + len] = max(dp[r][r + len], dp[r][r + len + 1] + A[r + len + 1] * (P[r + len + 1] >= r && P[r + len + 1] <= r + len));
        }
    }

    int ans = 0;
    rep(i, N) ans = max(ans, dp[i + 1][i + 1]);
    cout << ans << endl;
}
