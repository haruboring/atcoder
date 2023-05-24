#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
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
