#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    set<pair<ll, ll>> hole;
    rep(i, N) hole.insert({a[i], b[i]});

    vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, 0));
    ll ans = 0;
    repp(i, 1, H + 1) {
        repp(j, 1, W + 1) {
            if (hole.count({i, j})) continue;
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1LL;
            ans += dp[i][j];
        }
    }

    cout << ans << endl;
}