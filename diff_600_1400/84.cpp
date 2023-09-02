#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];
    vector<ll> C(M), Y(M);
    rep(i, M) cin >> C[i] >> Y[i];

    map<ll, ll> mp;
    rep(i, M) mp[C[i]] = Y[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -1));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, min(N, i + 1)) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + X[i] + mp[j + 1]);
        }
    }

    ll ans = 0;
    rep(i, N + 1) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
}
