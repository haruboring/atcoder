#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;

    ll MOD = 1e9 + 7;

    vector<ll> dp(N + 1);

    dp[0] = 1;
    rep(i, N) {
        dp[i + 1] += dp[i];
        dp[i + 1] %= MOD;
        if (i + L <= N) {
            dp[i + L] += dp[i];
            dp[i + L] %= MOD;
        }
    }

    cout << dp[N] << endl;
}
