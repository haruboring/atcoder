#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int mod = 1000000007;

int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a = a * a % mod;
        b >>= 1;
        ret %= mod;
    }
    return ret;
}

signed main() {
    int n, r;
    cin >> n >> r;

    int c = 1;
    rep(i, n) {
        c *= i + 1;
        c %= mod;
    }
    int m = 1;
    rep(i, r) {
        m *= i + 1;
        m %= mod;
    }
    rep(i, n - r) {
        m *= i + 1;
        m %= mod;
    }

    debug(c);
    debug(m);

    // c * m ^(mod-2)
    int ans = fast_pow(m, mod - 2) * c % mod;
    cout << ans << endl;
}
