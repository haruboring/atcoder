#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200000 + 100);
vector<int> sz(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
    rep(i, n) sz[i] = 1;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        sz[ry] += sz[rx];
        sz[rx] = 0;
        return par[rx] = ry;
    }
}

signed main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> edges(N - 1);
    rep(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = make_tuple(w, u, v);
    }
    sort(all(edges));

    int ans = 0;

    init(N);

    rep(i, N - 1) {
        int w, u, v;
        tie(w, u, v) = edges[i];
        ans += w * sz[root(u)] * sz[root(v)];
        unite(u, v);
    }

    cout << ans << endl;
}