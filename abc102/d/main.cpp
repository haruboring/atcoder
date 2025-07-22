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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 1e18;
    vector<int> T = A;
    rep(i, N - 1) T[i + 1] += T[i];
    for (int s = 1; s < N - 2; s++) {
        // if (s != N - 3) continue;
        int l = T[s], r = T[N - 1] - l;
        // debug(l);
        // debug(r);

        int ll = lower_bound(all(T), (l + 1) / 2) - T.begin();
        // debug(ll);
        int a = T[ll], b = l - a;
        if (ll > 0) {
            int a_ = T[ll - 1], b_ = l - a_;
            if (abs(a_ - b_) < abs(a - b)) {
                a = a_, b = b_;
            }
            // debug(ll - 1);
        }

        int rr = lower_bound(all(T), l + (r + 1) / 2) - T.begin();
        // debug(rr);
        int c = T[rr] - l, d = r - c;
        if (rr > s + 1) {
            int c_ = T[rr - 1] - l, d_ = r - c_;
            if (abs(c_ - d_) < abs(c - d)) {
                c = c_, d = d_;
            }
            // debug(rr);
        }

        // cout << a << " " << b << " " << c << " " << d << endl;

        ans = min(ans, max({a, b, c, d}) - min({a, b, c, d}));
    }
    cout << ans << endl;
}
