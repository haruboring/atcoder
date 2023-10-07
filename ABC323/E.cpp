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

    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int MOD = 998244353;

    // dp[i][j]はi曲目までの曲をj秒以内に再生する確率を表す
    vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));

    // 初期条件
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= X; ++j) {
            // i曲目を再生しない場合
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;

            // i曲目を再生する場合
            if (j >= T[i - 1]) {
                dp[i][j] += dp[i - 1][j - T[i - 1]];
                dp[i][j] %= MOD;
            }
        }
    }

    // 時刻(X+0.5)秒後に曲1が再生されている確率を出力
    int answer = dp[0][X] % MOD;
    cout << answer << endl;

    return 0;
}