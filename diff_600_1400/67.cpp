#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll X;
    cin >> X;

    ll ans = 1e18;
    repp(i, 1, 10) {
        rep(j, 10) {
            int d = j - i;
            ll x = 0;
            ll tmp = i;
            rep(k, 18) {
                x = x * 10 + tmp;
                if (x >= X) ans = min(ans, x);
                tmp += d;
                if (tmp < 0 || tmp > 9) {
                    debug(x);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}