#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];

    rep(i, N) A[i]--;
    rep(i, Q) X[i]--;

    vector<vector<int>> dp(30, vector<int>(N));
    rep(i, N) dp[0][i] = A[i];
    rep(i, 29) rep(j, N) dp[i + 1][j] = dp[i][dp[i][j]];

    rep(i, Q) {
        bitset<30> s(Y[i]);
        int ans = X[i];
        rep(i, 30) if (s.test(i)) ans = dp[i][ans];
        cout << ans + 1 << endl;
    }
}
