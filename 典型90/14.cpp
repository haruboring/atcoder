#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> B(N);
    rep(i, N) cin >> B[i];

    sort(all(A));
    sort(all(B));

    ll ans = 0;
    rep(i, N) {
        ans += abs(A[i] - B[i]);
    }

    cout << ans << endl;
}