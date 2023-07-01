#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
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
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    vector<ll> L(M);
    rep(i, M) cin >> L[i];
    vector<ll> D(M);
    rep(i, M) cin >> D[i];

    ll ans = 0;
    rep(i, N) ans += P[i];

    vector<pair<ll, ll>> dl(M);
    rep(i, M) dl[i] = make_pair(D[i], L[i]);
    sort(all(dl));
    reverse(all(dl));
    sort(all(P));
    init(N + 1);
    rep(i, M) {
        int idx = lower_bound(all(P), dl[i].second) - P.begin();
        if (idx == N) continue;
        idx = root(idx);
        if (idx == N) continue;
        unite(idx, idx + 1);
        ans -= dl[i].first;
    }

    cout << ans << endl;
}