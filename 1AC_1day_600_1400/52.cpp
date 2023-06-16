#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int H, W;
vector<string> S(2000 + 100);
vector<vector<ll>> dp(2000 + 100, vector<ll>(2000 + 100, 0));
vector<vector<ll>> r_accum(2000 + 100, vector<ll>(2000 + 100, 0));
vector<vector<ll>> d_accum(2000 + 100, vector<ll>(2000 + 100, 0));
vector<vector<ll>> rd_accum(2000 + 100, vector<ll>(2000 + 100, 0));
ll MOD = 1e9 + 7;

int main() {
    cin >> H >> W;
    rep(i, H) cin >> S[i];

    dp[0][0] = 1;
    r_accum[0][0] = 1;
    d_accum[0][0] = 1;
    rd_accum[0][0] = 1;
    rep(i, H) {
        rep(j, W) {
            if (i == 0 && j == 0) continue;
            if (S[i][j] == '#') continue;
            if (i == 0) {
                dp[i][j] += d_accum[i][j - 1];
                d_accum[i][j] = d_accum[i][j - 1] + dp[i][j];
                r_accum[i][j] += dp[i][j];
                rd_accum[i][j] += dp[i][j];
            }
            if (j == 0) {
                dp[i][j] += r_accum[i - 1][j];
                d_accum[i][j] += dp[i][j];
                r_accum[i][j] = r_accum[i - 1][j] + dp[i][j];
                rd_accum[i][j] += dp[i][j];
            }
            if (i > 0 && j > 0) {
                dp[i][j] += rd_accum[i - 1][j - 1] + d_accum[i][j - 1] + r_accum[i - 1][j];
                r_accum[i][j] = r_accum[i - 1][j] + dp[i][j];
                d_accum[i][j] = d_accum[i][j - 1] + dp[i][j];
                rd_accum[i][j] = rd_accum[i - 1][j - 1] + dp[i][j];
            }
            dp[i][j] %= MOD;
            r_accum[i][j] %= MOD;
            d_accum[i][j] %= MOD;
            rd_accum[i][j] %= MOD;
        }
    }

    cout << dp[H - 1][W - 1] % MOD << endl;
}