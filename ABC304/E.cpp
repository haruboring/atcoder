#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
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
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i];
    int K;
    cin >> K;
    vector<int> x(K), y(K);
    set<pair<int, int>> S;
    rep(i, K) {
        cin >> x[i] >> y[i];
        S.insert(make_pair(x[i], y[i]));
        S.insert(make_pair(y[i], x[i]));
    }
    int Q;
    cin >> Q;
    vector<int> p(Q), q(Q);
    rep(i, Q) cin >> p[i] >> q[i];

    init(N);
    vector<bool> ans(Q);

    rep(i, M) {
        if (root(u[i]) == root(v[i])) continue;
        unite(u[i], v[i]);
    }

    set<int> rot;
    set<pair<int, int>> mm;
    rep(i, K) {
        if (root(x[i]) == root(y[i])) {
            rep(i, Q) {
                cout << "No" << endl;
            }
            return 0;
        }
        mm.insert(make_pair(root(x[i]), root(y[i])));
        mm.insert(make_pair(root(y[i]), root(x[i])));
    }

    rep(i, Q) {
        int pr = root(p[i]);
        int qr = root(q[i]);
        if (mm.count(make_pair(pr, qr))) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
