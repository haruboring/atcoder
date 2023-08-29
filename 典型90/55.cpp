#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    ll cnt = 0;
    rep(i, N - 4) repp(j, i + 1, N - 3) repp(k, j + 1, N - 2) repp(l, k + 1, N - 1) repp(m, l + 1, N) {
        ll tmp = A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P;
        if (tmp == Q) ans++;
        cnt++;
    }

    debug(cnt);
    cout << ans << endl;
}
