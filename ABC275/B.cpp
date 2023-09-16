#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll BASE = 998244353;
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    ll ans = 0;
    ans = (((((A % BASE) * (B % BASE)) % BASE) * (C % BASE)) % BASE - ((((D % BASE) * (E % BASE)) % BASE) * (F % BASE)) % BASE + BASE) % BASE;
    cout << ans << endl;
}