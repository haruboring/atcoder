#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'000 + 100);
vector<int> cnt(200'000 + 100, 0);

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
    if (ry > rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        cnt[ry] += cnt[rx];
        cnt[rx] = 0;
        return par[rx] = ry;
    }
}

signed main() {
    int N, Q;
    cin >> N >> Q;

    init(N);
    vector<bool> c(N, false);

    rep(_, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            unite(u, v);
        } else if (f == 2) {
            int v;
            cin >> v;
            v--;
            if (c[v] == false) {
                cnt[root(v)]++;
            } else {
                cnt[root(v)]--;
            }

            c[v] = !c[v];
        } else {
            int v;
            cin >> v;
            v--;

            if (cnt[root(v)] > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
