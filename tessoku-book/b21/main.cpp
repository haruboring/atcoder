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

    string rS = S;
    reverse(all(rS));

    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    rep(i, N + 1) {
        rep(j, N + 1) {
            if (i < N && j < N && S[i] == rS[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            if (i < N) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < N) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        }
    }

    cout << dp[N][N] << endl;
}
