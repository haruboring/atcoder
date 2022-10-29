#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll BASE = 998244353;
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    ll ans = 0;
    ans = (((((A % BASE) * (B % BASE)) % BASE) * (C % BASE)) % BASE - ((((D % BASE) * (E % BASE)) % BASE) * (F % BASE)) % BASE + BASE) % BASE;
    cout << ans << endl;
}