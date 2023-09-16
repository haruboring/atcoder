#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll ans = 0;

    ll i = 1;
    while (i <= N) {
        ll j = N / i;
        ll k = N / j;
        ll s = k - i + 1;
        ans += j * s;
        i += s;
    }
    cout << ans << endl;
}
