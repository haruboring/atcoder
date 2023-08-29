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
    vector<vector<ll>> A(N, vector<ll>(6));
    rep(i, N) rep(j, 6) cin >> A[i][j];

    ll MOD = 1e9 + 7;

    ll ans = 1;
    rep(i, N) {
        ll sum = 0;
        rep(j, 6) {
            sum += A[i][j];
            sum %= MOD;
        }
        ans *= sum;
        ans %= MOD;
    }
    cout << ans << endl;
}
