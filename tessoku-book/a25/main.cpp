#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    rep(i, H) {
        rep(j, W) {
            if (i + 1 < H && S[i + 1][j] != '#') dp[i + 1][j] += dp[i][j];
            if (j + 1 < W && S[i][j + 1] != '#') dp[i][j + 1] += dp[i][j];
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}
