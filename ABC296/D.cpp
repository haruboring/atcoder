#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 9223372036854775807;
    repp(i, 1, sqrt(M) + 2) {
        ll k = M / i;
        if (M % i != 0) {
            k++;
        }
        if (k <= N && i <= N) {
            ans = min(ans, k * i);
        }
    }
    if (ans == 9223372036854775807) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}