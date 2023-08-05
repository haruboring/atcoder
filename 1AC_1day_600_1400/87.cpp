#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

vector<int> par(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), C(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> C[i];

    rep(i, N) X[i]--;

    init(N);
    ll ans = 0;
    rep(i, N) {
        if (root(i) != root(X[i])) {
            unite(i, X[i]);
            continue;
        }
        ll cost = C[i], v = i;
        do {
            unite(v, X[v]);
            cost = min(cost, C[v]);
            v = X[v];
        } while (v != i);
        ans += cost;
    }
    cout << ans << endl;
}
