#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;

    rep(i, T) {
        vector<int> A(5), P(5);
        rep(i, 5) cin >> A[i];
        rep(i, 5) cin >> P[i];

        int lack = 2 * A[0] + A[1] - A[3] - 2 * A[4];
        if (lack <= 0) {
            cout << 0 << endl;
            continue;
        }

        if (2 * P[3] < P[4]) {
            // debug("koko");
            cout << P[3] * lack << endl;
            continue;
        }

        else {
            // zenbu P[4]
            int ans = P[4] * ((lack + 1) / 2);
            // debug(ans);
            ans = min(ans, P[4] * ((lack) / 2) + P[3]);

            // debug("koko2");
            cout << ans << endl;
            continue;
        }
    }
}
