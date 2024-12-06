#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    map<int, set<pair<int, int>>> coasts;
    rep(i, W) {
        coasts[A[0][i]].insert({0, i});
        coasts[A[H - 1][i]].insert({H - 1, i});
    }
    rep(i, H) {
        coasts[A[i][W - 1]].insert({i, W - 1});
        coasts[A[i][0]].insert({i, 0});
    }

    debug(coasts[1].size());

    set<pair<int, int>> disappeared;
    repp(i, 1, Y + 1) {
        queue<pair<int, int>> q;
        for (auto p : coasts[i]) q.push(p);

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            if (disappeared.count({y, x})) continue;
            disappeared.insert({y, x});

            if (y > 0) {
                if (A[y - 1][x] > i) {
                    coasts[A[y - 1][x]].insert({y - 1, x});
                } else if (!disappeared.count({y - 1, x})) {
                    q.push({y - 1, x});
                }
            }
            if (y < H - 1) {
                if (A[y + 1][x] > i) {
                    coasts[A[y + 1][x]].insert({y + 1, x});
                } else if (!disappeared.count({y + 1, x})) {
                    q.push({y + 1, x});
                }
            }
            if (x > 0) {
                if (A[y][x - 1] > i) {
                    coasts[A[y][x - 1]].insert({y, x - 1});
                } else if (!disappeared.count({y, x - 1})) {
                    q.push({y, x - 1});
                }
            }
            if (x < W - 1) {
                if (A[y][x + 1] > i) {
                    coasts[A[y][x + 1]].insert({y, x + 1});
                } else if (!disappeared.count({y, x + 1})) {
                    q.push({y, x + 1});
                }
            }
        }
        cout << H * W - disappeared.size() << endl;
    }
}