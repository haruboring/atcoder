#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<vector<ll>> dp(2, vector<ll>(N + 1, 0));
    dp[0][0] = 0;
    dp[1][0] = 0;

    rep(i, N) {
        if (X[i] == 0) {
            dp[0][i + 1] = max(dp[0][i], dp[0][i] + Y[i]);
            dp[0][i + 1] = max(dp[0][i + 1], dp[1][i] + Y[i]);
            dp[1][i + 1] = max(dp[1][i + 1], dp[1][i]);
        } else {
            dp[0][i + 1] = max(dp[0][i + 1], dp[0][i]);
            dp[1][i + 1] = max(dp[1][i], dp[0][i] + Y[i]);
        }
    }

    cout << max(dp[0][N], dp[1][N]) << endl;
}