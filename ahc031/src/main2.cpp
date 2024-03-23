#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// https://atcoder.jp/contests/ahc031/submissions/51532131
signed main() {
    int W, D, N;
    cin >> W >> D >> N;
    vector<vector<int>> a(D, vector<int>(N));
    rep(i, D) rep(j, N) cin >> a[i][j];

    // W = 1000, 各日の予約数はNで一定

    vector<vector<tuple<int, int, int, int>>> rect(D, vector<tuple<int, int, int, int>>(N));
    rep(i, D) {
        int used_width = 0;
        rep(j, N) {
            // Wで割り切った区間を提供
            int width = min(W - used_width, (a[i][j] + W - 1) / W);
            rect[i][j] = {used_width, 0, used_width + width, W};
            used_width += width;
        }
    }

    rep(i, D) {
        rep(j, N) {
            auto [i0, j0, i1, j1] = rect[i][j];

            cout << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
        }
    }
}