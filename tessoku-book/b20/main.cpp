#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e18));
    dp[0][0] = 0;
    rep(i, N + 1) {
        rep(j, M + 1) {
            if (i < N && j < M && S[i] == T[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (i < N && j < M) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
            if (i < N) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j < M) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
        }
    }
    cout << dp[N][M] << endl;
}
