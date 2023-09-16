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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll BASE = 998244353;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(i + 2, vector<ll>(i, 0)));
        dp[0][0][0] = 1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= min(i, j); k++) {
                for (int l = 0; l < i; l++) {
                    dp[j + 1][k][l] += dp[j][k][l];
                    dp[j + 1][k][l] %= BASE;
                    dp[j + 1][k + 1][(l + A[j]) % i] += dp[j][k][l];
                    dp[j + 1][k + 1][(l + A[j]) % i] %= BASE;
                }
            }
        }
        ans += dp[N][i][0];
        ans %= BASE;
    }
    cout << ans << endl;
}