#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, C;
    cin >> H >> W >> C;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    map<int, int> m;
    rep(i, H + W + 10) m[i] = 1e18;
    map<int, tuple<int, int, int>> tt;
    vector<tuple<int, int, int>> a, b;
    rep(i, H) rep(j, W) a.push_back({A[i][j], i, j});

    sort(all(a));
    auto [x0, xi0, xj0] = a[0];
    tt[0] = {x0, xi0, xj0};

    for (auto [x, xi, xj] : a) {
        vector<tuple<int, int, int>> nb;
        for (auto [d_, v] : tt) {
            auto [y, yi, yj] = v;
            int d = abs(xi - yi) + abs(xj - yj);
            int cst = x + y + d * C;
            if (m[d] <= cst) continue;

            m[d] = cst;
        }
    }

    int ans = 1e18;
    rep(i, H + W + 5) ans = min(ans, m[i + 1]);
    cout << ans << endl;
}
