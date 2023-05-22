#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll H, N;
vector<ll> dp(10000 + 10, 1e9);
vector<ll> A(10000 + 10), B(10000 + 10);
ll ans = 1e9;

void attack(ll damaged) {
    rep(i, N) {
        if (damaged + A[i] < H) {
            dp[damaged + A[i]] = min(dp[damaged + A[i]], dp[damaged] + B[i]);
        } else {
            ans = min(ans, dp[damaged] + B[i]);
        }
    }
}

int main() {
    cin >> H >> N;
    rep(i, N) cin >> A[i] >> B[i];

    dp[0] = 0;

    rep(i, H) {
        if (dp[i] != 1e9) attack(i);
    }

    cout << ans << endl;
}