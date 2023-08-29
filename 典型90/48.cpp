#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<ll> point_per1(2 * N);
    rep(i, N) {
        point_per1[i] = A[i] - B[i];
        point_per1[i + N] = B[i];
    }
    sort(all(point_per1), greater<ll>());

    ll ans = 0;
    rep(i, min(2 * N, K)) {
        ans += point_per1[i];
    }
    cout << ans << endl;
}
