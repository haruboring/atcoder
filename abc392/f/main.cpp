#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using namespace atcoder;

vector<int> par(501000);

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
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

// 区間に足す
int op(int a, int b) { return a + b; }
int e() { return 0; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

signed main() {
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    lazy_segtree<int, op, e, int, mapping, composition, id> seg(N + 10);
    rep(i, N) seg.set(i, 0);

    init(N + 100);

    vector<int> ans(N + 10000);
    for (int i = N - 1; i >= 0; i--) {
        int p = P[i] - 1;
        int buff = seg.get(p);

        int np = root(p);
        rep(_, buff) {
            int nnp = root(np + 1);
            np = nnp;
        }

        ans[np] = i + 1;

        // debug(p + buff);
        // debug(np);

        unite(np, np + 1);
        // cout << "unite: " << np << ", " << np + 1 << endl;

        seg.apply(np, N + 1, 1);
    }

    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}
