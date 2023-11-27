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
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    rep(i, N) {
        if (i + 1 < N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    cout << dp[N - 1] << endl;
}