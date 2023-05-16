#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll MOD = 1'000'000'007;
int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    vector<ll> l(N + 1), r(N + 1);
    r[N] = N;
    for (ll i = 1LL; i < N + 1LL; i++) {
        l[i] = (l[i - 1] + i) % MOD;
        r[N - i] = (r[N - i + 1] + (N - i)) % MOD;
    }

    repp(i, K, N + 2) {
        ans += (r[N - i + 1] - l[i - 1] + 1 + MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}