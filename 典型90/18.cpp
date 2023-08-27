#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    ll L, X, Y;
    cin >> L >> X >> Y;
    ll Q;
    cin >> Q;
    vector<ll> E(Q);
    rep(i, Q) cin >> E[i];

    rep(i, Q) {
        double theta = 2 * M_PI * E[i] / T;
        double y = -L / 2.0 * sin(theta);
        double z = L / 2.0 * (1 - cos(theta));

        double dist = sqrt(X * X + (Y - y) * (Y - y));

        double arg = atan(z / dist);
        double ans = arg * 180 / M_PI;

        cout << fixed << setprecision(10) << ans << endl;
    }
}