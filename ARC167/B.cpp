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
    int A, B;
    cin >> A >> B;

    int MOD = 998244353;

    if (B == 0) {
        cout << 0 << endl;
        return 0;
    }

    if ((1 + B) % 2 == 0) {
        int ans = (1 + B) % MOD;
        ans *= modinv(2, MOD);
        ans %= MOD;
        int r = B % MOD;
        ans *= r;
        ans %= MOD;

        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}