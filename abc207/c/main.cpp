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
    double d = 0.1;
    vector<pair<double, double>> lr(N);
    rep(i, N) {
        int t;
        cin >> t;
        double l, r;
        cin >> l >> r;

        if (t == 1) {
            lr[i] = {l, r};
        } else if (t == 2) {
            lr[i] = {l, r - d};
        } else if (t == 3) {
            lr[i] = {l + d, r};
        } else {
            lr[i] = {l + d, r - d};
        }
    }

    int ans = 0;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            auto [li, ri] = lr[i];
            auto [lj, rj] = lr[j];

            if (ri >= lj && li <= rj) ans++;
        }
    }

    cout << ans << endl;
}
