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
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    sort(all(X));
    sort(all(Y));

    int x = X[N / 2], y = Y[N / 2];

    ll ans = 0;
    rep(i, N) {
        ans += abs(X[i] - x);
        ans += abs(Y[i] - y);
    }

    cout << ans << endl;
}
