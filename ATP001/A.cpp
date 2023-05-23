#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int H, W;
vector<string> S(500 + 10);
vector<vector<bool>> visited(500 + 10, vector<bool>(500 + 10, false));
vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (auto d : moves) {
        int nx = x + d[0], ny = y + d[1];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (S[nx][ny] == '#') continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny);
    }
}

int main() {
    cin >> H >> W;
    rep(i, H) cin >> S[i];

    int sx, sy, gx, gy;

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 's') {
                sx = i;
                sy = j;
            }
            if (S[i][j] == 'g') {
                gx = i;
                gy = j;
            }
        }
    }
    dfs(sx, sy);

    if (visited[gx][gy]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}