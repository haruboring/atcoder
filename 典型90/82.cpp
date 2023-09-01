#include "atcoder/all"
#include "bits/stdc++.h"
#define int unsigned long long
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
    int L, R;
    cin >> L >> R;

    int MOD = 1e9 + 7;

    int left_ans = 0;
    string str_L = to_string(L);

    repp(i, 1, str_L.size() + 1) {
        int s = powl(10, i - 1);
        int t = powl(10, i) - 1;

        t = min(t, L - 1);

        left_ans += (((((s + t) % MOD) * ((t - s + 1) % MOD) % MOD) * i) % MOD * modinv(2, MOD)) % MOD;
        left_ans %= MOD;
    }

    int right_ans = 0;
    string str_R = to_string(R);
    repp(i, 1, str_R.size() + 1) {
        int s = powl(10, i - 1);
        int t = powl(10, i) - 1;

        t = min(t, R);

        right_ans += (((((s + t) % MOD) * ((t - s + 1) % MOD) % MOD) * i) % MOD * modinv(2, MOD)) % MOD;
        right_ans %= MOD;
    }

    cout << (right_ans - left_ans + MOD) % MOD << endl;
}
