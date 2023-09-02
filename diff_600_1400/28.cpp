#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll BASE = 1e9 + 7;
ll N, P;

ll fast_pow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % BASE;
        a = a * a % BASE;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> N >> P;
    // ans = (P-1) * (P-2)^(N-1)
    ll ans = (P - 1) % BASE;
    ans = ans * fast_pow(P - 2, N - 1) % BASE;
    cout << ans << endl;
}