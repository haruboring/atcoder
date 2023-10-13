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
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    int total = 0;
    rep(i, N) total += T[i];

    vector<vector<int>> dp(N + 1, vector<int>(1e5 + 100, -1));

    dp[0][0] = 0;
    rep(i, N) {
        rep(j, 1e5 + 100) {
            if (dp[i][j] == -1) continue;

            dp[i + 1][j] = 1;
            dp[i + 1][j + T[i]] = 1;
        }
    }

    int ans = 1e9;
    rep(i, 1e5 + 100) {
        if (dp[N][i] == 1) ans = min(ans, max(i, total - i));
    }

    cout << ans << endl;
}