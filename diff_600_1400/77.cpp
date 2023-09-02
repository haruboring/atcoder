#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> L(K), R(K);
    rep(i, K) cin >> L[i] >> R[i];

    ll MOD = 998244353;
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        ans += dp[i];
        for (int j = 0; j < K; j++) {
            int l = i + L[j];
            int r = i + R[j] + 1;
            if (l > N) continue;
            dp[l] += ans;
            dp[l] %= MOD;
            if (r > N) continue;
            dp[r] += MOD - ans;
            dp[r] %= MOD;
        }
    }

    cout << dp[N] << endl;
}