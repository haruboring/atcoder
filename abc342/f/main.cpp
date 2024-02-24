#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

double op(double a, double b) { return a + b; }
double e() { return 0; }

signed main() {
    int N, L, D;
    cin >> N >> L >> D;

    atcoder::lazy_segtree<double, op, e, double, op, op, e> seg(N + D + 10);
    seg.set(0, 1);
    rep(i, N) {
        int l = i + 1;
        int r = i + D + 1;

        seg.apply(l, r, seg.get(i) / D);
    }
    // 0.625
    atcoder::lazy_segtree<double, op, e, double, op, op, e> seg2(N + D + 10);
    seg2.set(0, 1);
    rep(i, L) {
        int l = i + 1;
        int r = i + D + 1;

        seg2.apply(l, r, seg2.get(i) / D);
    }
    rep(i, L) seg2.set(i, 0);

    debug(seg2.prod(N + 1, N + D + 10));
    double ans = seg2.prod(N + 1, N + D + 10) * seg.prod(0, N + 1);
    repp(i, 1, N + 1) {
        ans += seg2.prod(0, i) * seg.get(i);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
