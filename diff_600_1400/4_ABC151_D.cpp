#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

// AtCoder Beginner ContestのD問題を解く
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int ans = 0;

    vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            vector<vector<int>> dist(H, vector<int>(W, -1));
            queue<pair<int, int>> q;
            dist[i][j] = 0;
            q.push(make_pair(i, j));
            int max_dist = 0;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto step : d) {
                    int nx = x + step[0];
                    int ny = y + step[1];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if (S[nx][ny] == '#') continue;
                    if (dist[nx][ny] != -1) continue;
                    dist[nx][ny] = dist[x][y] + 1;
                    max_dist = max(max_dist, dist[nx][ny]);
                    q.push(make_pair(nx, ny));
                }
            }
            ans = max(ans, max_dist);
        }
    }
    cout << ans << endl;
}