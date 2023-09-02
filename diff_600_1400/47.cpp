#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll MOD = 998244353;

    // xx - y = zz (zは0以上の整数)
    // xx - zz = y
    // (x-z)(x+z) = y
    // ab = y

    ll ans = 0;
    repp(a, 1, sqrt(N) + 1) {
        ll max_b = (N / a);
        if (max_b % 2 != a % 2) max_b--;
        ans += (max_b + 1) / 2;
        ans -= (a + 1) / 2 - 1;
        ans %= MOD;
    }

    cout << ans << endl;
}