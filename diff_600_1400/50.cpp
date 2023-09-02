#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W, rs, cs;
    cin >> H >> W >> rs >> cs;
    int N;
    cin >> N;
    vector<int> r(N), c(N);
    rep(i, N) cin >> r[i] >> c[i];
    int Q;
    cin >> Q;
    vector<char> d(Q);
    vector<int> l(Q);
    rep(i, Q) cin >> d[i] >> l[i];

    map<int, vector<int>> LR_wall, UD_wall;
    set<int> r_have_wall, c_have_wall;
    rep(i, N) {
        r_have_wall.insert(r[i]);
        c_have_wall.insert(c[i]);
        LR_wall[r[i]].push_back(c[i]);
        UD_wall[c[i]].push_back(r[i]);
    }
    for (auto r : r_have_wall) {
        LR_wall[r].push_back(0);
        LR_wall[r].push_back(W + 1);
        sort(all(LR_wall[r]));
    }
    for (auto c : c_have_wall) {
        UD_wall[c].push_back(0);
        UD_wall[c].push_back(H + 1);
        sort(all(UD_wall[c]));
    }

    int now_r = rs, now_c = cs;
    rep(i, Q) {
        if (d[i] == 'L') {
            if (LR_wall[now_r].empty()) {
                now_c -= min(l[i], now_c - 1);
            } else {
                now_c -= min(l[i], now_c - *(lower_bound(all(LR_wall[now_r]), now_c) - 1) - 1);
            }
        }
        if (d[i] == 'R') {
            if (LR_wall[now_r].empty()) {
                now_c += min(l[i], W - now_c);
            } else {
                now_c += min(l[i], *lower_bound(all(LR_wall[now_r]), now_c) - now_c - 1);
            }
        }
        if (d[i] == 'U') {
            if (UD_wall[now_c].empty()) {
                now_r -= min(l[i], now_r - 1);
            } else {
                now_r -= min(l[i], now_r - *(lower_bound(all(UD_wall[now_c]), now_r) - 1) - 1);
            }
        }
        if (d[i] == 'D') {
            if (UD_wall[now_c].empty()) {
                now_r += min(l[i], H - now_r);
            } else {
                now_r += min(l[i], *lower_bound(all(UD_wall[now_c]), now_r) - now_r - 1);
            }
        }
        cout << now_r << " " << now_c << endl;
    }
}