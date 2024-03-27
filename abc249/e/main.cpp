#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int fast_pow(int a, int b, int MOD) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int N, P;
    cin >> N >> P;

    // T_length, original_length
    vector<vector<int>> dp(5000 + 1, vector<int>(5000 + 1, 0)), sum(5000 + 1, vector<int>(5000 + 1, 0));

    dp[0][0] = 26 * fast_pow(25, P - 2, P) % P;
    rep(i, N) sum[0][i + 1] = dp[0][0];
    vector<int> ten = {1, 10, 100, 1000, 5000};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= 4; k++) {
                if (i - k - 1 < 0) continue;
                int x = max(0LL, j - ten[k - 1] + 1), y = max(0LL, j - ten[k] + 1);
                dp[i][j] += 25 * (sum[i - k - 1][x] - sum[i - k - 1][y] + P);
                dp[i][j] %= P;
            }
            sum[i][j + 1] = sum[i][j] + dp[i][j];
            sum[i][j + 1] %= P;
        }
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans += dp[i][N];
        ans %= P;
    }

    cout << ans << endl;
}
