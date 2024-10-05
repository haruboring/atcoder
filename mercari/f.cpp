// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<int>> dp(N + 1, vector<int>(100 * 100 + 250, -1));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, 100 * 100 + 100) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = 1;
            dp[i + 1][j + A[i]] = 1;
        }
    }

    // int ans = 0;
    int mi = 1e9;
    rep(i, N + 1) {
        repp(j, X, 100 * 100 + 100) {
            if (dp[i][j] == 1) mi = min(mi, j);
        }
    }
    int mi2 = 1e9;
    rep(i, N + 1) {
        repp(j, 2 * X, 100 * 100 + 100) {
            if (dp[i][j] == 1) mi2 = min(mi2, j);
        }
    }

    int all = 0;
    rep(i, N) all += A[i];

    if (mi > 1e8) {
        cout << all << endl;
        return 0;
    }
    if (mi2 > 1e8) {
        int ans = 0;
        ans += mi + 2 * (all - mi);
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    ans += mi + 2 * (mi2 - mi) + 3 * (all - mi2);
    cout << ans << endl;
}