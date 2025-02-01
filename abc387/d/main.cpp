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

    int si, sj, gi, gj;
    rep(i, H) rep(j, W) {
        if (S[i][j] == 'S') si = i, sj = j;
        if (S[i][j] == 'G') gi = i, gj = j;
    }

    vector<vector<int>> dist_c0(H, vector<int>(W, 1e9)), dist_c1(H, vector<int>(W, 1e9));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;

    pq.push({0, si, sj, -1});
    dist_c1[si][sj] = 0;
    dist_c0[si][sj] = 0;
    // c == 1なら横移動、c == 0なら縦移動
    while (!pq.empty()) {
        auto [d, i, j, c] = pq.top();
        pq.pop();
        if (c == 0) {
            if (d > dist_c0[i][j]) continue;
        } else if (c == 1) {
            if (d > dist_c1[i][j]) continue;
        }

        if (c == 0 || c == -1) {
            for (auto [di, dj] : vector<pair<int, int>>{{0, 1}, {0, -1}}) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (S[ni][nj] == '#') continue;
                if (d + 1 >= dist_c1[ni][nj]) continue;
                dist_c1[ni][nj] = d + 1;
                pq.push({d + 1, ni, nj, 1});
            }
        }

        if (c == 1 || c == -1) {
            for (auto [di, dj] : vector<pair<int, int>>{{1, 0}, {-1, 0}}) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (S[ni][nj] == '#') continue;
                if (d + 1 >= dist_c0[ni][nj]) continue;
                dist_c0[ni][nj] = d + 1;
                pq.push({d + 1, ni, nj, 0});
            }
        }
    }

    int ans = min(dist_c1[gi][gj], dist_c0[gi][gj]);
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}
