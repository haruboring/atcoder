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
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    deque<pair<int, pair<int, int>>> que;
    que.push_back({0, {0, 0}});
    vector<vector<int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> broken = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    while (!que.empty()) {
        auto [d, xy] = que.front();
        auto [x, y] = xy;
        que.pop_front();

        if (dist[x][y] <= d) continue;
        dist[x][y] = d;

        rep(i, 4) {
            int nx = x + dxy[i][0];
            int ny = y + dxy[i][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (S[nx][ny] == '#') {
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (dist[nx][ny] <= d + 1) continue;
                que.push_back({d + 1, {nx, ny}});

                rep(j, 8) {
                    int nnx = nx + broken[j][0];
                    int nny = ny + broken[j][1];
                    if (nnx < 0 || nnx >= H || nny < 0 || nny >= W) continue;
                    if (dist[nnx][nny] <= d + 1) continue;
                    que.push_back({d + 1, {nnx, nny}});
                }
            } else {
                if (dist[nx][ny] <= d) continue;
                que.push_front({d, {nx, ny}});
            }
        }
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist[H - 1][W - 1] << endl;
}
