#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int MOD = 1000000007;

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
    int N, A, B;
    cin >> N >> A >> B;

    int ans = fast_pow(2, N, MOD);
    ans--;

    int comb_A = 1, comb_B = 1;
    rep(i, A) {
        comb_A *= (N - i);
        comb_A %= MOD;
        comb_A *= fast_pow(i + 1, MOD - 2, MOD);
        comb_A %= MOD;
    }
    rep(i, B) {
        comb_B *= (N - i);
        comb_B %= MOD;
        comb_B *= fast_pow(i + 1, MOD - 2, MOD);
        comb_B %= MOD;
    }

    ans = (ans - comb_A - comb_B + MOD * 2) % MOD;

    cout << ans << endl;
}
