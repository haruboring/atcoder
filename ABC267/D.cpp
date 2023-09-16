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
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1e18));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, M + 1) {
            if (dp[i][j] == -1e18) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < M) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (j + 1) * A[i]);
        }
    }

    cout << dp[N][M] << endl;
}