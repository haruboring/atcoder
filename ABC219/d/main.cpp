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
    int X, Y;
    cin >> X >> Y;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 1e9));
    dp[0][0] = 0;
    rep(i, N) {
        for (int j = X; j >= 0; j--) {
            for (int k = Y; k >= 0; k--) {
                if (dp[j][k] == 1e9) continue;
                dp[min(j + A[i], X)][min(k + B[i], Y)] = min(dp[min(j + A[i], X)][min(k + B[i], Y)], dp[j][k] + 1);
            }
        }
    }
    if (dp[X][Y] == 1e9) dp[X][Y] = -1;
    cout << dp[X][Y] << endl;
}
