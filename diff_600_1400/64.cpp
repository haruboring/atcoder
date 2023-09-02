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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll MOD = 1e9 + 7;

    vector<ll> rev(N);
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            if (A[i] > A[j]) rev[i]++;
        }
    }

    vector<ll> rev2(N);
    rep(i, N) {
        rep(j, N) {
            if (A[i] > A[j]) rev2[i]++;
        }
    }

    ll ans = 0;
    K %= MOD;
    rep(i, N) {
        ans += ((K * (K - 1)) / 2) % MOD * rev2[i] % MOD;
        ans %= MOD;
        ans += K * rev[i] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
