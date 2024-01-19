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
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e9));
    rep(i, N + 1) dp[i][0] = i;
    rep(j, M + 1) dp[0][j] = j;
    rep(i, N) {
        rep(j, M) {
            dp[i + 1][j + 1] = min({dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + (A[i] != B[j])});
        }
    }
    cout << dp[N][M] << endl;
}
