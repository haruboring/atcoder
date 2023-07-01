#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<int>> visited(H, vector<int>(W, -1));
    string sunuke = "snuke";  // 5
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int x = 0, y = 0;
    queue<pair<int, int>> q;
    visited[x][y] = 0;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == H - 1 && y == W - 1) {
            cout << "Yes" << endl;
            return 0;
        }
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (visited[nx][ny] != -1) continue;
            if (S[nx][ny] != sunuke[(visited[x][y] + 1) % 5]) continue;
            visited[nx][ny] = (visited[x][y] + 1) % 5;
            q.push(make_pair(nx, ny));
        }
    }
    cout << "No" << endl;
}