#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(201000);

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

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) {
        A[i]--;
        B[i]--;
    }

    vector<tuple<int, int, int>> rest(0);
    init(N);
    rep(i, M) {
        if (root(A[i]) == root(B[i])) {
            rest.push_back({i, A[i], B[i]});
        } else {
            unite(A[i], B[i]);
        }
    }

    vector<tuple<int, int, int>> ans(0);
    set<int> g;
    rep(i, N) g.insert(root(i));

    for (auto [i, a, b] : rest) {
        if (g.size() == 1) break;
        int x = *g.begin();
        g.erase(x);
        if (root(a) == root(x)) {
            int y = *g.begin();
            g.insert(x);
            g.erase(y);
            x = y;
        }
        ans.push_back({i, a, x});
        unite(a, x);
    }

    cout << ans.size() << endl;
    for (auto [i, a, b] : ans) cout << i + 1 << " " << a + 1 << " " << b + 1 << endl;
}
