#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    int sx, sy, gx, gy;
    rep(i, H) {
        rep(j, W) {
            if (A[i][j] == 'S') sx = i, sy = j;
            if (A[i][j] == 'G') gx = i, gy = j;
        }
    }
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, 1e18)));
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<tuple<int, int, int, bool>>> p;
    p.push({0LL, sx, sy, true});
    while (!p.empty()) {
        auto [d, x, y, f] = p.top();
        p.pop();
        // debug(d);
        if (d >= dist[x][y][f]) continue;
        dist[x][y][f] = d;
        // debug(d);

        for (auto [dx, dy] : moves) {
            int nx = x + dx, ny = y + dy;
            if (nx >= H || nx < 0) continue;
            if (ny >= W || ny < 0) continue;

            if (A[nx][ny] == '#') continue;
            if (A[nx][ny] == 'o' && f == false) continue;
            if (A[nx][ny] == 'x' && f == true) continue;
            bool nf = f;
            if (A[nx][ny] == '?') nf = !nf;
            p.push({d + 1, nx, ny, nf});
        }
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << dist[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // debug("sa");
    //     rep(i, H) {
    //     rep(j, W) {
    //         cout << dist[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = -1;
    if (min(dist[gx][gy][0], dist[gx][gy][1]) == 1e18) {
        cout << -1 << endl;
        return 0;
    }
    cout << min(dist[gx][gy][0], dist[gx][gy][1]) << endl;
}
