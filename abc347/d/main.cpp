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
    int N;
    cin >> N;
    vector<int> R(N), C(N), E(N);
    rep(i, N) cin >> R[i] >> C[i] >> E[i];

    rep(i, N) R[i]--, C[i]--;

    map<pair<int, int>, int> med;
    rep(i, N) {
        med[{R[i], C[i]}] = E[i];
    }

    pair<int, int> s, t;
    rep(i, H) rep(j, W) {
        if (A[i][j] == 'S') s = {i, j};
        if (A[i][j] == 'T') t = {i, j};
    }

    debug(s.first);

    // r[i], c[i]の距離を全て求める
    map<tuple<int, int, int, int>, int> dist;
    rep(i, N) {
        int br = R[i], bc = C[i];
        vector<vector<int>> d(H, vector<int>(W, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, br, bc});
        while (!q.empty()) {
            auto [dd, r, c] = q.top();
            q.pop();
            d[r][c] = dd;
            for (auto [dr, dc] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (A[nr][nc] == '#') continue;
                if (d[nr][nc] == 1e9) {
                    d[nr][nc] = dd + 1;
                    q.push({dd + 1, nr, nc});
                }
            }
            // debug(dd);
        }

        rep(j, N) {
            dist[{br, bc, R[j], C[j]}] = d[R[j]][C[j]];
        }
    }
}
