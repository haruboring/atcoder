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
    vector<int> x(N), y(N), c(N);
    rep(i, N) cin >> x[i] >> y[i] >> c[i];

    int ans = 0;

    double l = 0, r = 1e9;
    rep(_, 100) {
        double m = (l + r) / 2;
        double com_xl = -1e9, com_xr = 1e9;
        rep(i, N) {
            double dx = m / c[i];
            com_xl = max(com_xl, x[i] - dx);
            com_xr = min(com_xr, x[i] + dx);
        }
        double com_yl = -1e9, com_yr = 1e9;
        rep(i, N) {
            double dy = m / c[i];
            com_yl = max(com_yl, y[i] - dy);
            com_yr = min(com_yr, y[i] + dy);
        }

        if (com_xl <= com_xr && com_yl <= com_yr) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << fixed << setprecision(10) << r << endl;
}
