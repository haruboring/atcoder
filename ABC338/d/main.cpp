#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    rep(i, M) cin >> X[i];

    vector<int> vv(N);
    rep(i, M) X[i]--;

    int ans = 0;
    rep(i, M - 1) {
        int mi = min(X[i], X[i + 1]);
        int ma = max(X[i], X[i + 1]);

        debug(ma - mi);
        debug(N - ma + mi);

        if (ma - mi < N - ma + mi) {
            vv[mi] += (N - ma + mi) - (ma - mi);
            vv[ma] -= (N - ma + mi) - (ma - mi);
        } else {
            vv[0] += (ma - mi) - (N - ma + mi);
            vv[mi] -= (ma - mi) - (N - ma + mi);
            vv[ma] += (ma - mi) - (N - ma + mi);
        }

        ans += min(ma - mi, N - ma + mi);
    }

    rep(i, N - 1) vv[i + 1] += vv[i];

    cout << ans + *min_element(all(vv)) << endl;
}
