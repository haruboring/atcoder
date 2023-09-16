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
    vector<string> a(H);
    rep(i, H) {
        cin >> a[i];
    }
    pair<int, int> S, G;
    vector<vector<pair<int, int>>> tele('z' + 1, vector<pair<int, int>>(0));
    rep(i, H) {
        rep(j, W) {
            if (a[i][j] == 'S') {
                S = make_pair(i, j);
            }
            if (a[i][j] == 'G') {
                G = make_pair(i, j);
            }
            if ('a' <= a[i][j] && a[i][j] <= 'z') {
                tele[a[i][j]].push_back(make_pair(i, j));
            }
        }
    }

    vector<vector<int>> dis(H, vector<int>(W, 4000000 + 100));
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    dis[S.first][S.second] = 0;
    queue<pair<int, int>> q;
    q.push(S);
    set<char> visited_char;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        rep(i, 4) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (0 <= next_x && next_x < H && 0 <= next_y && next_y < W && a[next_x][next_y] != '#') {
                if (dis[x][y] + 1 < dis[next_x][next_y]) {
                    dis[next_x][next_y] = dis[x][y] + 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
        if (islower(a[x][y]) && !visited_char.count(a[x][y])) {
            for (auto [next_x, next_y] : tele[a[x][y]]) {
                if (dis[x][y] + 1 < dis[next_x][next_y]) {
                    dis[next_x][next_y] = dis[x][y] + 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
            visited_char.insert(a[x][y]);
        }
    }
    if (dis[G.first][G.second] == 4000000 + 100) {
        cout << -1 << endl;
    } else {
        cout << dis[G.first][G.second] << endl;
    }
}