#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    unordered_map<int, int> s2p;
    rep(i, H) rep(j, W) s2p[A[i][j]] = 10000 * i + j;

    map<pair<int, int>, int> ans;
    repp(l, 1, D + 1) {
        int x = s2p[l] / 10000, y = s2p[l] % 10000;
        int cost = 0;
        ans[{l % D, l}] = cost;

        for (int xs = l + D; xs <= H * W; xs += D) {
            int nx = s2p[xs] / 10000, ny = s2p[xs] % 10000;
            int d = abs(nx - x) + abs(ny - y);
            cost += d;
            ans[{l % D, xs}] = cost;

            x = nx, y = ny;
        }
    }

    rep(i, Q) cout << ans[{L[i] % D, R[i]}] - ans[{L[i] % D, L[i]}] << endl;
}
