#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

const int MAX = 102000;
ll MOD = 998244353;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll kai(ll n) {
    ll ans = 1;
    repp(i, 1, n + 1) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}
int main() {
    ll N;
    cin >> N;
    vector<ll> D(N);
    rep(i, N) cin >> D[i];

    if (D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    sort(all(D));
    if (D[1] != 1) {
        cout << 0 << endl;
        return 0;
    }
    ll now = 1;
    repp(i, 2, N) {
        if (D[i] == now)
            continue;
        else if (D[i] == now + 1)
            now++;
        else {
            cout << 0 << endl;
            return 0;
        }
    }

    map<ll, ll> mp;
    rep(i, N) mp[D[i]]++;
    ll ans = 1;
    COMinit();
    for (auto p : mp) {
        if (p.first == 0 || p.first == 1) continue;
        rep(i, p.second) {
            ans *= mp[p.first - 1];
            ans %= MOD;
        }
    }

    cout << ans << endl;
}