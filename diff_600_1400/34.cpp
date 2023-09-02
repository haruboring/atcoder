#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(M), b(M), c(M);
    vector<int> u(Q), v(Q), w(Q);
    rep(i, M) cin >> a[i] >> b[i] >> c[i];
    rep(i, Q) cin >> u[i] >> v[i] >> w[i];

    vector<vector<int>> es(M + Q, vector<int>(4));
    rep(i, M) {
        es[i][0] = c[i];
        es[i][1] = a[i];
        es[i][2] = b[i];
        es[i][3] = -1;
    }
    rep(i, Q) {
        es[M + i][0] = w[i];
        es[M + i][1] = u[i];
        es[M + i][2] = v[i];
        es[M + i][3] = i;
    }

    sort(all(es));

    init(N);
    vector<bool> ans(Q);

    rep(i, es.size()) {
        int a = es[i][1], b = es[i][2], idx = es[i][3];
        if (idx == -1) {
            if (root(a) != root(b)) unite(a, b);
        } else {
            if (root(a) == root(b)) {
                ans[idx] = false;
            } else {
                ans[idx] = true;
            }
        }
    }
    rep(i, Q) {
        if (ans[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}