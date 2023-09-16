#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll a, b, ans = 1;
    cin >> a >> b;
    ll BASE = 1000000007;
    vector<ll> v(50);
    v[0] = 1;
    v[1] = a;
    repp(i, 2, 50) {
        v[i] = v[i - 1] * v[i - 1];
        v[i] %= BASE;
    }
    while (b > 0) {
        ll k;
        rep(i, 50) {
            if (pow(2, i) <= b) {
                k = i + 1;
            }
        }
        ans *= v[k];
        ans %= BASE;
        b -= pow(2, k - 1);
    }
    cout << ans << endl;
}