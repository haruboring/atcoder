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
    vector<double> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<int> b(N, 1);
    rep(i, N - 1) b[i + 1] = 2 * b[i];

    // 集合/最後/最初
    vector<vector<vector<double>>> dp((1 << N), vector<vector<double>>(N, vector<double>(N, 1e18)));
    rep(i, N) dp[b[i]][i][i] = 0;
    rep(i, ((1 << N))) {
        rep(ni, N) {
            rep(si, N) {
                rep(li, N) {
                    dp[i | b[ni]][ni][si] = min(dp[i | b[ni]][ni][si], dp[i][li][si] + sqrt((X[ni] - X[li]) * (X[ni] - X[li]) + (Y[ni] - Y[li]) * (Y[ni] - Y[li])));
                }
            }
        }
    }

    double ans = 1e18;
    rep(i, N) {
        rep(j, N) {
            dp[(1 << N) - 1][i][j] += sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
            ans = min(ans, dp[(1 << N) - 1][i][j]);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
