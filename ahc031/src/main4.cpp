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

    // 溢れを最小化
    rep(i, D) {
        vector<pair<int, int>> tmp(N);
        rep(j, N) tmp[j] = {a[i][j] % W, j};
        sort(all(tmp));
        reverse(all(tmp));

        map<int, int> mw;

        int used_width = 0;
        rep(j, N - 1) {
            auto [amari, idx] = tmp[j];
            // Wで割り切った区間を提供
            int width = min(W - used_width, (a[i][idx] + W - 1) / W);
            mw[idx] = width;
            used_width += width;
        }
        auto [amari, idx] = tmp[N - 1];
        mw[idx] = W - used_width;

        used_width = 0;
        rep(j, N) {
            int width = mw[j];

            cout << used_width << " " << 0 << " " << used_width + width << " " << W << endl;

            used_width += width;
        }
    }
}
