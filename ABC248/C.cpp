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
    ll BASE = 998244353;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, K) {
            rep(k, M) {
                if (j + k + 1 <= K) {
                    dp[i + 1][j + k + 1] += dp[i][j];
                    dp[i + 1][j + k + 1] %= BASE;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, K) {
        ans += dp[N][i + 1];
        ans %= BASE;
    }
    cout << ans << endl;
}