#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int H, W;
vector<string> c(16);

int ans = -1;

vector<vector<int>> dist(16, vector<int>(16, -1));
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, int sx, int sy) {
    for (auto [dx, dy] : moves) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (c[nx][ny] == '#') continue;
        if (nx == sx && ny == sy) {
            ans = max(ans, dist[x][y] + 1);
            continue;
        }
        if (dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        dfs(nx, ny, sx, sy);
        // dist[nx][ny] = -1;
    }
}

int main() {
    cin >> H >> W;
    rep(i, H) cin >> c[i];

    rep(i, H) {
        rep(j, W) {
            if (c[i][j] == '#') continue;
            dist.assign(16, vector<int>(16, -1));
            dist[i][j] = 0;
            dfs(i, j, i, j);
        }
    }

    if (ans < 3) ans = -1;

    cout << ans << endl;
}
