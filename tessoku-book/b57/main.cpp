#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(40, vector<int>(N + 1));
    rep(i, N + 1) {
        string s = to_string(i);
        int sum = 0;
        rep(i, s.size()) sum += s[i] - '0';
        dp[0][i] = i - sum;
    }

    rep(i, 37) rep(j, N + 1) dp[i + 1][j] = dp[i][dp[i][j]];

    repp(i, 1, N + 1) {
        bitset<37> s(K);
        int ans = i;
        rep(i, 37) if (s.test(i)) ans = dp[i][ans];

        cout << ans << endl;
    }
}
