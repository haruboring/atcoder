#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<tuple<int, int, int>> t;
    rep(i, N) t.push_back({X[i], Y[i], i});
    sort(all(t));

    atcoder::dsu uf(N);

    set<pair<int, int>> s;
    s.insert({get<1>(t[0]), 0});

    repp(i, 1, N) {
        auto [x, y, _] = t[i];
        set<pair<int, int>> erased;
        pair<int, int> tt = {1e18, -1};
        for (auto [cy, ci] : s) {
            if (cy < y) {
                uf.merge(i, ci);
                erased.insert({cy, ci});
                if (tt.first == 1e18) tt = {cy, ci};
            } else {
                break;
            }
        }
        for (auto [cy, ci] : erased) s.erase({cy, ci});
        if (tt.first != 1e18) {
            s.insert(tt);
        } else {
            s.insert({y, i});
        }
    }

    vector<int> ans(N);
    rep(i, N) ans[get<2>(t[i])] = uf.size(i);
    rep(i, N) cout << ans[i] << endl;
}
