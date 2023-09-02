#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

ll MOD = 998244353;

// a^n mod を計算する
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, P;
    cin >> N >> P;

    ll a = modpow(100, MOD - 2);

    vector<ll> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[max(i - 2, 0)] * (a * P % MOD) + dp[i - 1] * ((1 - a * P % MOD + MOD)) + 1) % MOD;
    }
    cout << dp[N] << endl;
}