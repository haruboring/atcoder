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
    string S;
    cin >> S;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    vector<vector<int>> dp(N, vector<int>(4, 1e18));
    if (S[0] == '0') {
        dp[0][0] = 0;
        dp[0][1] = C[0];
    } else {
        dp[0][0] = C[0];
        dp[0][1] = 0;
    }

    repp(i, 1, N) {
        if (S[i] == '0') {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + C[i]);

            dp[i][2] = min(dp[i][2], dp[i - 1][0]);
            dp[i][3] = min(dp[i][3], dp[i - 1][1] + C[i]);

            dp[i][2] = min(dp[i][2], dp[i - 1][3]);
            dp[i][3] = min(dp[i][3], dp[i - 1][2] + C[i]);
        } else {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + C[i]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);

            dp[i][2] = min(dp[i][2], dp[i - 1][0] + C[i]);
            dp[i][3] = min(dp[i][3], dp[i - 1][1]);

            dp[i][2] = min(dp[i][2], dp[i - 1][3] + C[i]);
            dp[i][3] = min(dp[i][3], dp[i - 1][2]);
        }
    }

    cout << min(dp[N - 1][2], dp[N - 1][3]) << endl;
}
