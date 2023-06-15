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
    vector<pair<int, int>> rc(N), cr(N);
    rep(i, N) cin >> rc[i].first >> rc[i].second;
    rep(i, N) cr[i] = make_pair(rc[i].second, rc[i].first);
    int Q;
    cin >> Q;
    vector<char> d(Q);
    vector<int> l(Q);
    rep(i, Q) cin >> d[i] >> l[i];

    sort(all(rc));
    sort(all(cr));
    map<int, vector<int>> LR_wall, UD_wall;
    set<int> r_have_wall, c_have_wall;
    rep(i, N) {
        r_have_wall.insert(rc[i].first);
        c_have_wall.insert(rc[i].second);
        LR_wall[rc[i].first].push_back(rc[i].second);
        UD_wall[cr[i].first].push_back(cr[i].second);
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

    int r = rs, c = cs;
    rep(i, Q) {
        if (d[i] == 'L') {
            if (LR_wall[r].empty()) {
                c -= min(l[i], c - 1);
            } else {
                c -= min(l[i], c - *(lower_bound(all(LR_wall[r]), c) - 1) - 1);
            }
        }
        if (d[i] == 'R') {
            if (LR_wall[r].empty()) {
                c += min(l[i], W - c);
            } else {
                c += min(l[i], *lower_bound(all(LR_wall[r]), c) - c - 1);
            }
        }
        if (d[i] == 'U') {
            if (UD_wall[c].empty()) {
                r -= min(l[i], r - 1);
            } else {
                r -= min(l[i], r - *(lower_bound(all(UD_wall[c]), r) - 1) - 1);
            }
        }
        if (d[i] == 'D') {
            if (UD_wall[c].empty()) {
                r += min(l[i], H - r);
            } else {
                r += min(l[i], *lower_bound(all(UD_wall[c]), r) - r - 1);
            }
        }
        cout << r << " " << c << endl;
    }
}