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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> B(N - 2);
    rep(i, N - 2) B[i] = A[i + 2];

    ll low = A[0], up = A[1];
    sort(all(B));
    ll ans = 1e18;
    rep(i, N - 1 - M) {
        ll l = B[i];
        ll u = B[i + M - 1];
        ll need_low = max(0LL, low - l);
        ll need_up = max(0LL, u - up);
        ans = min(ans, need_low + need_up);
    }
    cout << ans << endl;
}