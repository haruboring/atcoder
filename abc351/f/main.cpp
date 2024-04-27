#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using S = int;
S op(S a, S b) {
    return S((a + b));
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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(A), cnt(N);
    rep(i, N) cnt.set(i, 1);

    map<int, vector<int>> mp;
    rep(i, N) mp[A[i]].push_back(i);

    int ans = 0;
    for (auto [a, idxs] : mp) {
        for (int idx : idxs) {
            int sum = seg.prod(idx + 1, N);
            int cnt_sum = cnt.prod(idx + 1, N);
            ans += sum - a * cnt_sum;

            seg.set(idx, 0);
            cnt.set(idx, 0);
        }
    }

    cout << ans << endl;
}
