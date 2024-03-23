#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W, D, N;
    cin >> W >> D >> N;
    vector<vector<int>> a(D, vector<int>(N));
    rep(i, D) rep(j, N) cin >> a[i][j];

    // W = 1000, 各日の予約数はNで一定

    map<int, vector<tuple<int, int, int, int>>> rect;
    rep(i, D) {
        rep(j, N) {
            rect[i].push_back({(W / N) * j, 0, (W / N) * (j + 1), W});
        }
    }

    rep(i, D) {
        rep(j, N) {
            auto [i0, j0, i1, j1] = rect[i][j];

            cout << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
        }
    }
}
