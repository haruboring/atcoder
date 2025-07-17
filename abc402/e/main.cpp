#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<double> S(N), C(N), P(N);
    rep(i, N) cin >> S[i] >> C[i] >> P[i];

    rep(i, N) P[i] /= 100;

    vector<vector<double>> dp(X + 1, vector<double>(1 << N, 0));
    rep(x, X + 1) {
        rep(state, 1 << N) {
            rep(np, N) {
                if ((state >> np) & 1) continue;
                int nstate = state | (1 << np);
                int nx = x - C[np];
                if (nx < 0) continue;
                dp[x][state] = max(dp[x][state], P[np] * (S[np] + dp[nx][nstate]) + (1 - P[np]) * (dp[nx][state]));
            }
        }
    }
    cout << fixed << setprecision(20) << dp[X][0] << endl;
}
