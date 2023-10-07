#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int llpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

// a^n mod を計算する
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
int modinv(int a, int mod) {
    return modpow(a, mod - 2, mod);
}

signed main() {
    int N, X;
    cin >> N >> X;

    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    int MOD = 998244353;

    vector<int> dp(X + 10, 0);

    dp[0] = 1;
    rep(i, X) {
        rep(j, N) {
            if (i + T[j] > X) continue;
            int tmp = dp[i] * modinv(N, MOD) % MOD;
            dp[i + T[j]] += tmp;
            dp[i + T[j]] %= MOD;
        }
    }

    int ans = 0;
    repp(i, max(0LL, X - T[0] + 1), X + 1) {
        ans += dp[i];
        ans %= MOD;
    }

    ans *= modinv(N, MOD);

    cout << ans % MOD << endl;
}