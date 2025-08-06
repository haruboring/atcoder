#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(N);
    rep(i, N) cin >> B[i];

    vector<vector<mint>> dp(N + 1, vector<mint>(3000 + 10, -1));
    repp(i, A[0], B[0] + 1) dp[1][i] = 1;
    repp(i, 1, N) {
        for (int s = A[i]; s <= B[i]; s++) {
            dp[i + 1][s] = 0;
            if (dp[i + 1][s - 1] == -1) {
                rep(k, s + 1) if (dp[i][k] != -1) dp[i + 1][s] += dp[i][k];
            } else {
                dp[i + 1][s] = dp[i + 1][s - 1];
                if (dp[i][s] != -1) dp[i + 1][s] += dp[i][s];
            }
        }
    }

    mint sum = 0;
    rep(i, 3000 + 10) if (dp[N][i] != -1) sum += dp[N][i];
    cout << sum.val() << endl;
}
