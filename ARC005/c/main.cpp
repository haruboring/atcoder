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
    vector<string> c(H);
    rep(i, H) cin >> c[i];

    pair<int, int> s, g;
    rep(i, H) {
        rep(j, W) {
            if (c[i][j] == 's') s = make_pair(i, j);
            if (c[i][j] == 'g') {
                g = make_pair(i, j);
                c[i][j] = '.';
            }
        }
    }

    queue<pair<int, int>> q, q1, q2;
    q.push(s);
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    dist[s.first][s.second] = 0;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    // 距離0のみ
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        rep(i, 4) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (c[nx][ny] == '#' && dist[nx][ny] > 1) {
                dist[nx][ny] = 1;
                q1.push(make_pair(nx, ny));
            }
            if (c[nx][ny] == '.' && dist[nx][ny] > 0) {
                dist[nx][ny] = 0;
                q.push(make_pair(nx, ny));
            }
        }
    }
    // 距離1のみ
    while (!q1.empty()) {
        pair<int, int> now = q1.front();
        q1.pop();
        rep(i, 4) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (c[nx][ny] == '#' && dist[nx][ny] > 2) {
                dist[nx][ny] = 2;
                q2.push(make_pair(nx, ny));
            }
            if (c[nx][ny] == '.' && dist[nx][ny] > 1) {
                dist[nx][ny] = 1;
                q1.push(make_pair(nx, ny));
            }
        }
    }

    // 距離2のみ
    while (!q2.empty()) {
        pair<int, int> now = q2.front();
        q2.pop();
        rep(i, 4) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (c[nx][ny] == '#' && dist[nx][ny] > 3) {
                dist[nx][ny] = 3;
            }
            if (c[nx][ny] == '.' && dist[nx][ny] > 2) {
                dist[nx][ny] = 2;
                q2.push(make_pair(nx, ny));
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            cerr << dist[i][j] << " ";
        }
        cerr << endl;
    }

    if (dist[g.first][g.second] <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
