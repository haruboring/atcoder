#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(10));
    ll BASE = 998244353;
    rep(i, 10) {
        dp[1][i] = 1;
    }
    repp(i, 1, N) {
        repp(j, 1, 10) {
            if (j == 1) {
                dp[i + 1][j + 1] += dp[i][j] % BASE;
                dp[i + 1][j] += dp[i][j] % BASE;
            } else if (1 < j && j < 9) {
                dp[i + 1][j + 1] += dp[i][j] % BASE;
                dp[i + 1][j] += dp[i][j] % BASE;
                dp[i + 1][j - 1] += dp[i][j] % BASE;
            } else if (j == 9) {
                dp[i + 1][j] += dp[i][j] % BASE;
                dp[i + 1][j - 1] += dp[i][j] % BASE;
            }
        }
    }
    ll ans = 0;
    rep(i, 9) {
        ans += dp[N][i + 1];
        ans %= BASE;
    }
    cout << ans << endl;
}