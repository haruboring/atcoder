#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<mint>> dp(N, vector<mint>(2));
    dp[0][0] = 1;
    rep(i, N - 1) {
        dp[i + 1][0] = dp[i][0] + dp[i][1];
        dp[i + 1][1] = dp[i][0];
    }

    mint o = dp[N - 1][0], z = dp[N - 1][1], a = o + z;
    mint ans = o * A[N - 1] - z * A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        z = o * dp[i][1] / dp[i + 1][0];
        o = a - z;
        ans += o * A[i] - z * A[i];
    }

    cout << ans.val() << endl;
}
