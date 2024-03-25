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

    vector<vector<tuple<int, int, int, int>>> rect(D, vector<tuple<int, int, int, int>>(N));
    rep(i, D) {
        int used_width = 0;
        vector<pair<int, int>> p(N);
        rep(j, N) p[j] = {a[i][j] % W, j};
        sort(all(p));
        rep(j, N - 1) {
            // Wで割り切った区間を提供
            int idx = p[j].second;
            int width = min(W - used_width, (a[i][idx] + W - 1) / W);
            rect[i][idx] = {used_width, 0, used_width + width, W};
            used_width += width;
        }
        int idx = p[N - 1].second;
        rect[i][idx] = {used_width, 0, W, W};
    }

    rep(i, D) {
        rep(j, N) {
            auto [i0, j0, i1, j1] = rect[i][j];

            cout << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
        }
    }
}