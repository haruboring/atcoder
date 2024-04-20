#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// apple, Apple, APPLE, lazy_segtree
using S = int;
S op(S a, S b) {
    return S(max(a, b));
}
S e() {
    return S(0);
}
using F = int;
S mapping(F f, S x) {
    return S(f + x);
}
F composition(F f, F g) {
    return F(f + g);
}
F id() {
    return F(0);
}

signed main() {
    int N, D, W;
    cin >> N >> D >> W;
    vector<int> T(N), X(N);
    rep(i, N) cin >> T[i] >> X[i];

    map<int, vector<int>> mp;
    rep(i, N) mp[T[i]].push_back(X[i]);

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(200010 + W);
    for (auto [t, xs] : mp) {
        if (t > D) break;
        for (int x : xs) {
            seg.apply(x, x + W, 1);
        }
    }
    int ans = -1;
    repp(t, 1, 200010) {
        ans = max(ans, seg.prod(0, 200010));
        if (mp.count(t) != 0) {
            for (int x : mp[t]) {
                seg.apply(x, x + W, -1);
            }
        }
        if (mp.count(t + D) != 0) {
            for (int x : mp[t + D]) {
                seg.apply(x, x + W, 1);
            }
        }
    }

    cout << ans << endl;
}
