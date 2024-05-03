#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

const int MAX = 1001000;
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
    int X, Y;
    cin >> X >> Y;

    mint ans = 0;
    COMinit();
    for (int i = 0; i <= X; i++) {
        int j = X - i;
        if (j % 2 == 1) continue;
        int y = j / 2 + 2 * i;
        if (y != Y) continue;

        ans += COM(i + j / 2, i);
    }

    cout << ans.val() << endl;
}
