#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll ans = 0;
    vector<ll> Y;
    repp(i, 1, sqrt(M) + 1) {
        if (M % i == 0) {
            Y.push_back(i);
            Y.push_back(M / i);
        }
    }
    sort(all(Y));
    rep(i, Y.size()) {
        if (M % Y[i] == 0 && Y[i] * N <= M) ans = Y[i];
    }

    cout << ans << endl;
}