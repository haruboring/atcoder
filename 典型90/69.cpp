#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

ll fast_pow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 1;

    rep(i, min(2LL, N)) {
        ans *= K - i;
        ans %= MOD;
    }
    if (N >= 2) {
        ans *= fast_pow(K - 2, N - 2);
    }

    cout << ans % MOD << endl;
}
