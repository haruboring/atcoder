#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<int>> m(M, vector<int>(L));
    rep(ama, M) {
        vector<int> t(L);
        rep(i, N) t[i % L] += (M + ama - (A[i] % M)) % M;
        m[ama] = t;
    }

    vector<vector<int>> dp(N, vector<int>(M, 1e18));
    rep(i, M) dp[0][i] = m[i][0];
    rep(i, L - 1) {
        rep(ama, M) {
            rep(add, M) {
                dp[i + 1][(ama + add) % M] = min(dp[i + 1][(ama + add) % M], dp[i][ama] + m[add][i + 1]);
            }
        }
    }

    cout << dp[L - 1][0] << endl;
}
