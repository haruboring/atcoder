#include "atcoder/all"
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
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    vector<int> dp(X + 200, 1e18);
    dp[0] = 0;
    rep(i, N) {
        vector<int> next_dp = dp;
        rep(j, X + 1) {
            if (dp[j] == i) {
                next_dp[j + a[i]] = dp[j] + 1;
                next_dp[j + b[i]] = dp[j] + 1;
            }
        }
        dp = next_dp;
    }

    if (dp[X] == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
