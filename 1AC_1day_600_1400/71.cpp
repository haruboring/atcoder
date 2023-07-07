#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string X;
    cin >> X;

    vector<int> dp(N + 1);
    dp[0] = 0;
    repp(i, 1, N + 1) {
        bitset<32> b(i);
        if (b.count() <= 0) continue;
        dp[i] = dp[i % b.count()] + 1;
    }

    int cnt_1 = 0;
    rep(i, N) {
        if (X[i] == '1') cnt_1++;
    }

    ll X_int_m = 0;
    rep(i, N) {
        if (cnt_1 <= 1) continue;
        X_int_m *= 2;
        X_int_m += X[i] - '0';
        X_int_m %= (cnt_1 - 1);
        X_int_m += (cnt_1 - 1);
        X_int_m %= (cnt_1 - 1);
    }
    ll X_int_p = 0;
    rep(i, N) {
        X_int_p *= 2;
        X_int_p += X[i] - '0';
        X_int_p %= (cnt_1 + 1);
    }

    vector<ll> pow2_m(N + 1), pow2_p(N + 1);
    pow2_m[0] = 1;
    pow2_p[0] = 1;
    repp(i, 1, N + 1) {
        pow2_p[i] = pow2_p[i - 1] * 2 % (cnt_1 + 1);
        if (cnt_1 <= 1) continue;
        pow2_m[i] = pow2_m[i - 1] * 2 % (cnt_1 - 1);
    }

    reverse(all(X));
    vector<int> ans(N);
    rep(i, N) {
        if (X[i] == '0') {
            ans[i] = dp[(X_int_p + pow2_p[i]) % (cnt_1 + 1)] + 1;
        } else {
            if (cnt_1 <= 1) {
                ans[i] = 0;
                continue;
            }
            ans[i] = dp[((X_int_m - pow2_m[i]) % (cnt_1 - 1) + cnt_1 - 1) % (cnt_1 - 1)] + 1;
        }
    }
    reverse(all(ans));

    rep(i, N) cout << ans[i] << endl;
}