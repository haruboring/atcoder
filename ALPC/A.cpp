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
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), U(Q), V(Q);
    rep(i, Q) cin >> T[i] >> U[i] >> V[i];

    init(N);
    rep(i, Q) {
        int t = T[i];
        int u = U[i];
        int v = V[i];

        if (t == 0) {
            unite(u, v);
        } else {
            if (root(u) == root(v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}