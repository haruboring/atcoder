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

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> coasts;
    set<pair<int, int>> is_coasts;
    rep(i, W) {
        coasts.push({A[0][i], 0, i});
        coasts.push({A[H - 1][i], H - 1, i});
        is_coasts.insert({0, i});
        is_coasts.insert({H - 1, i});
    }
    rep(i, H) {
        coasts.push({A[i][W - 1], i, W - 1});
        coasts.push({A[i][0], i, 0});
        is_coasts.insert({i, W - 1});
        is_coasts.insert({i, 0});
    }

    set<pair<int, int>> disappeared;
    rep(i, Y) {
        set<pair<int, int>> is_disappearing;
        while (!coasts.empty()) {
            queue<pair<int, int>> disappearing;
            auto [a, y, x] = coasts.top();
            if (a > i + 1) break;
            coasts.pop();

            disappearing.push({y, x});
            is_disappearing.insert({y, x});

            while (!disappearing.empty()) {
                auto [y, x] = disappearing.front();
                disappearing.pop();
                disappeared.insert({y, x});
                if (y > 0 && !disappeared.count({y - 1, x})) {
                    if (A[y - 1][x] > i + 1 && !is_coasts.count({y - 1, x})) {
                        coasts.push({A[y - 1][x], y - 1, x});
                        is_coasts.insert({y - 1, x});
                    } else if (A[y - 1][x] <= i + 1 && !is_disappearing.count({y - 1, x})) {
                        disappearing.push({y - 1, x});
                        is_disappearing.insert({y - 1, x});
                    }
                }
                if (y < H - 1 && !disappeared.count({y + 1, x})) {
                    if (A[y + 1][x] > i + 1 && !is_coasts.count({y + 1, x})) {
                        coasts.push({A[y + 1][x], y + 1, x});
                        is_coasts.insert({y + 1, x});
                    } else if (A[y + 1][x] <= i + 1 && !is_disappearing.count({y + 1, x})) {
                        disappearing.push({y + 1, x});
                        is_disappearing.insert({y + 1, x});
                    }
                }
                if (x > 0 && !disappeared.count({y, x - 1})) {
                    if (A[y][x - 1] > i + 1 && !is_coasts.count({y, x - 1})) {
                        coasts.push({A[y][x - 1], y, x - 1});
                        is_coasts.insert({y, x - 1});
                    } else if (A[y][x - 1] <= i + 1 && !is_disappearing.count({y, x - 1})) {
                        disappearing.push({y, x - 1});
                        is_disappearing.insert({y, x - 1});
                    }
                }
                if (x < W - 1 && !disappeared.count({y, x + 1})) {
                    if (A[y][x + 1] > i + 1 && !is_coasts.count({y, x + 1})) {
                        coasts.push({A[y][x + 1], y, x + 1});
                        is_coasts.insert({y, x + 1});
                    } else if (A[y][x + 1] <= i + 1 && !is_disappearing.count({y, x + 1})) {
                        disappearing.push({y, x + 1});
                        is_disappearing.insert({y, x + 1});
                    }
                }
            }
        }
        cout << H * W - disappeared.size() << endl;
    }
}