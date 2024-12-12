#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using mint = atcoder::modint998244353;

const int MAX = 1010;
mint fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

mint COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

signed main() {
    int K;
    cin >> K;
    vector<int> C(26);
    rep(i, 26) cin >> C[i];

    vector<vector<mint>> dp(26 + 1, vector<mint>(K + 1, 0));
    dp[0][0] = 1;
    COMinit();

    rep(i, 26) {
        rep(j, K + 1) {
            rep(k, min(j, C[i]) + 1) {
                dp[i + 1][j] += dp[i][j - k] * COM(j, k);
            }
        }
    }

    mint ans = 0;
    repp(i, 1, K + 1) {
        ans += dp[26][i];
    }

    // repp(i, 0, 26 + 1) {
    //     repp(j, 0, K + 1) {
    //         cerr << dp[i][j].val() << " ";
    //     }
    //     cerr << endl;
    // }

    cout << ans.val() << endl;
}
