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
    vector<int> a(M), b(M);
    vector<vector<int>> c(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j, b[i]) cin >> c[i][j];
    }

    vector<int> dp(1 << N, 1e9);
    dp[0] = 0;
    rep(i, (1 << N)) {
        if (dp[i] == 1e9) continue;
        rep(j, M) {
            int s = 0;
            rep(k, b[j]) s |= (1 << (c[j][k] - 1));
            dp[i | s] = min(dp[i | s], dp[i] + a[j]);
        }
    }

    if (dp[(1 << N) - 1] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << N) - 1] << endl;
    }
}
