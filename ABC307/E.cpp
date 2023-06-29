#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll MOD = 998244353;

    vector<vector<ll>> dp(2, vector<ll>(N));
    // 1番目と一緒ではない
    dp[0][0] = 0;
    // 1番目と一緒
    dp[1][0] = M;
    rep(i, N - 1) {
        dp[0][i + 1] = dp[0][i] * (M - 2) + dp[1][i] * (M - 1);
        dp[1][i + 1] = dp[0][i];
        dp[0][i + 1] %= MOD;
        dp[1][i + 1] %= MOD;
    }

    cout << dp[0][N - 1] << endl;
}