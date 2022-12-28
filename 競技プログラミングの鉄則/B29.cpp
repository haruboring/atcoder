#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    ll BASE = 1000000007;
    vector<ll> v(70);
    v[0] = 1;
    v[1] = a;
    repp(i, 2, 70) {
        v[i] = v[i - 1] * v[i - 1];
        v[i] %= BASE;
    }
    ll ans = 1;
    bitset<70> s(b);
    rep(i, 70) {
        if (s.test(i)) {
            ans *= v[i + 1];
            ans %= BASE;
        }
    }
    cout << ans << endl;
}