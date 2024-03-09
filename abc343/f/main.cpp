#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

tuple<int, int, int, int> op(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    set<int> s;
    auto [av1, ac1, av2, ac2] = a;
    auto [bv1, bc1, bv2, bc2] = b;

    map<int, int> mp;
    mp[av1] += ac1;
    mp[av2] += ac2;
    mp[bv1] += bc1;
    mp[bv2] += bc2;

    vector<pair<int, int>> v;
    for (auto [key, value] : mp) v.push_back({key, value});
    sort(all(v));
    reverse(all(v));

    tuple<int, int, int, int> res;
    res = {v[0].first, v[0].second, v[1].first, v[1].second};

    return res;
}

tuple<int, int, int, int> e() {
    return {0, 0, 0, 0};
}

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<tuple<int, int, int, int>> tm(N);
    rep(i, N) {
        tm[i] = {A[i], 1, 0, 0};
    }

    atcoder::segtree<tuple<int, int, int, int>, op, e> seg(tm);

    rep(i, Q) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            seg.set(l - 1, {r, 1, 0, 0});
        } else {
            auto [v1, c1, v2, c2] = seg.prod(l - 1, r);
            cout << c2 << endl;
        }
    }
}
