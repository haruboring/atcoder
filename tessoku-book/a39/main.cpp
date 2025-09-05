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
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    map<int, int> m;
    rep(i, N) {
        if (m[L[i]] == 0) {
            m[L[i]] = R[i];
        } else {
            m[L[i]] = min(m[L[i]], R[i]);
        }
    }
    vector<int> dp(1e5);
    int t = 0;
    rep(i, 1e5) {
        t = max(t, dp[i]);
        dp[i] = t;
        if (m[i] != 0) {
            dp[m[i]] = dp[i] + 1;
        }
    }

    cout << dp[1e5 - 1] << endl;
}
