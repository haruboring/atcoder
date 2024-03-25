#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W, D, N;
    cin >> W >> D >> N;
    vector<vector<int>> a(D, vector<int>(N));
    rep(i, D) rep(j, N) cin >> a[i][j];

    // W = 1000, 各日の予約数はNで一定

    // 半分にする
    int hW = W / 2;
    vector<vector<tuple<int, int, int, int>>> left_rect(D, vector<tuple<int, int, int, int>>(0)), right_rect(D, vector<tuple<int, int, int, int>>(0));
    rep(i, D) {
        int used_left_width = 0, used_right_width = 0;
        vector<int> sorted_a = a[i];
        sort(all(sorted_a));
        reverse(all(sorted_a));
        rep(j, N - 2) {
            // Wで割り切った区間を提供
            if (j % 2 == 0) {
                int width = min(W - used_left_width, (sorted_a[j] + hW - 1) / hW);
                left_rect[i].push_back({used_left_width, 0, used_left_width + width, hW});
                used_left_width += width;
            } else {
                int width = min(W - used_right_width, (sorted_a[j] + hW - 1) / hW);
                right_rect[i].push_back({used_right_width, hW, used_right_width + width, W});
                used_right_width += width;
            }
        }
        repp(j, N - 2, N) {
            if (j % 2 == 0) {
                left_rect[i].push_back({used_left_width, 0, W, hW});
            } else {
                right_rect[i].push_back({used_right_width, hW, W, W});
            }
        }
    }

    rep(i, D) {
        vector<pair<int, int>> tmp;
        rep(j, N) tmp.push_back({a[i][j], j});
        sort(all(tmp));
        reverse(all(tmp));

        map<int, int> order;
        rep(j, N) {
            order[tmp[j].second] = j;
        }
        rep(j, N) {
            int idx = order[j];
            if (idx % 2 == 0) {
                auto [i0, j0, i1, j1] = left_rect[i][idx / 2];

                cout << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
            } else {
                auto [i0, j0, i1, j1] = right_rect[i][idx / 2];

                cout << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
            }
        }
    }
}