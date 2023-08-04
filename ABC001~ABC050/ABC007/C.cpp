#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int dis[55][55];
string c[55];
int R, C, sy, sx, gy, gx;

bool check(int x, int y, int di) {
    return (0 < x && x <= C && 0 < y && y <= R && c[y][x] == '.' && di < dis[y][x]);
}

void bfs(int x, int y, int di) {
    dis[y][x] = di;
    if (check(x + 1, y, di + 1)) {
        bfs(x + 1, y, di + 1);
    }
    if (check(x - 1, y, di + 1)) {
        bfs(x - 1, y, di + 1);
    }
    if (check(x, y + 1, di + 1)) {
        bfs(x, y + 1, di + 1);
    }
    if (check(x, y - 1, di + 1)) {
        bfs(x, y - 1, di + 1);
    }
}

int main() {
    cin >> R >> C >> sy >> sx >> gy >> gx;
    rep(i, R) {
        string cc;
        cin >> cc;
        c[i + 1] = " " + cc;
    }
    rep(i, 55) {
        rep(j, 55) {
            dis[i][j] = 9999;
        }
    }
    dis[sy][sx] = 0;
    bfs(sx, sy, 0);
    // rep(i, R+1) {
    //     rep(j, C+1) {
    //         cout << setw(2) << setfill('0') << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dis[gy][gx] << endl;
}