#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll H, W;
    cin >> H >> W;
    // (H+W)_C_(H);
    H--;
    W--;
    ll BASE = 1000000007;
    ll ch = 1, mo = 1;
    rep(i, H) {
        ch *= (H + W) - i;
        ch %= BASE;
        mo *= (i + 1);
        mo %= BASE;
    }
    vector<ll> v(60);
    v[0] = mo;
    rep(i, 59) {
        v[i + 1] = v[i] * v[i];
        v[i + 1] %= BASE;
    }
    bitset<60> s(BASE - 2);
    rep(i, 60) {
        if (s.test(i)) {
            ch *= v[i];
            ch %= BASE;
        }
    }
    cout << ch << endl;
}