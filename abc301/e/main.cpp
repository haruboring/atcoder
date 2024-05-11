#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int start_idx, goal_idx;
    vector<int> X, Y;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'S') {
                start_idx = X.size();
                X.push_back(j);
                Y.push_back(i);
            } else if (S[i][j] == 'G') {
                goal_idx = X.size();
                X.push_back(j);
                Y.push_back(i);
            } else if (S[i][j] == 'o') {
                X.push_back(j);
                Y.push_back(i);
            }
        }
    }

    int N = X.size();
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(H, vector<int>(W, 1e9)));
    rep(i, N) {
        vector<vector<int>> d(H, vector<int>(W, 1e9));
        d[Y[i]][X[i]] = 0;
        queue<pair<int, int>> q;
        q.push({Y[i], X[i]});
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (abs(dy) + abs(dx) != 1) continue;
                    int ny = y + dy, nx = x + dx;
                    if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                    if (S[ny][nx] == '#') continue;
                    if (d[ny][nx] > d[y][x] + 1) {
                        d[ny][nx] = d[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
        rep(j, H) {
            rep(k, W) {
                dist[i][j][k] = d[j][k];
            }
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, 1e9));
    dp[1 << start_idx][start_idx] = 0;
    rep(bit, 1 << N) {
        rep(i, N) {
            rep(j, N) {
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][Y[j]][X[j]]);
            }
        }
    }

    int ans = 1;
    rep(i, 1 << N) {
        if (dp[i][goal_idx] <= T) {
            int cnt = 0;
            rep(j, N) {
                if (i & (1 << j)) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans - 2 << endl;
}
