#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll K;
    cin >> K;

    if (K % 9 != 0) {
        debug(K);
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(K + 1, 0);

    repp(i, 1, K + 1) {
        repp(j, 1, 10) {
            if (i - j == 0) break;
            dp[i] += dp[i - j];
            dp[i] %= 1000000007;
        }
        if (i < 10) {
            dp[i] += 1;
        }
        dp[i] %= 1000000007;
    }

    cout << dp[K] << endl;
}