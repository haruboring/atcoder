#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    reverse(all(A));

    vector<vector<int>> dp(2, vector<int>(K + 1));
    dp[0][0] = 2, dp[1][0] = 2;
    for (int i = 0; i < K; i++) {
        dp[1][i + 1] = A[i] * ((dp[1][i] + A[i] - 1) / A[i]);
        // debug(dp[1][i + 1]);
        dp[0][i + 1] = A[i] * (dp[0][i] / A[i]) + A[i] - 1;
        // debug(dp[0][i + 1]);
    }

    if (dp[0][K] < dp[1][K]) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[1][K] << " " << dp[0][K] << endl;
}
