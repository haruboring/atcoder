#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

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

signed main() {
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> T(Q), X(Q), Y(Q), V(Q);
    rep(i, Q) cin >> T[i] >> X[i] >> Y[i] >> V[i];

    rep(i, Q) {
        X[i]--;
        Y[i]--;
    }

    map<pair<int, int>, int> mp;
    rep(i, Q) {
        if (T[i] == 0) {
            mp[{X[i], Y[i]}] = V[i];
            mp[{Y[i], X[i]}] = V[i];
        }
    }

    init(N);

    rep(i, Q) {
        if (T[i] == 0) {
            unite(X[i], Y[i]);
        }
    }

    vector<int> C(N);
    vector<bool> even(N);

    C[0] = 0;
    even[0] = true;
    rep(i, N - 1) {
        int rx = root(i);
        int ry = root(i + 1);

        if (rx == ry) {
            C[i + 1] = mp[make_pair(i, i + 1)] - C[i];
            even[i + 1] = !even[i];
        } else {
            C[i + 1] = 0;
            even[i + 1] = true;
        }
    }

    init(N);

    rep(i, Q) {
        if (T[i] == 0) {
            unite(X[i], Y[i]);
        } else {
            if ((root(X[i]) != root(Y[i]))) {
                cout << "Ambiguous" << endl;
            } else {
                int d = V[i] - C[X[i]];
                if (even[X[i]] == even[Y[i]]) {
                    cout << C[Y[i]] + d << endl;
                } else {
                    cout << C[Y[i]] - d << endl;
                }
            }
        }
    }
}
