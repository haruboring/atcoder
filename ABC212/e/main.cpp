#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> U(M), V(M);
    rep(i, M) cin >> U[i] >> V[i];

    int MOD = 998244353;

    rep(i, M) {
        U[i]--;
        V[i]--;
    }

    vector<vector<int>> G(N);
    rep(i, M) {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    vector<vector<int>> dp(K + 1, vector<int>(N, 0));
    dp[0][0] = 1;
    vector<int> sum(K + 1);
    sum[0] = 1;
    rep(i, K) {
        int tmp = 0;
        rep(j, N) {
            dp[i + 1][j] = sum[i] - dp[i][j] + MOD;
            dp[i + 1][j] %= MOD;
            for (auto v : G[j]) {
                dp[i + 1][j] += MOD - dp[i][v];
                dp[i + 1][j] %= MOD;
            }
            tmp += dp[i + 1][j];
            tmp %= 998244353;
        }
        sum[i + 1] = tmp;
    }

    cout << dp[K][0] << endl;
}
