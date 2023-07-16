#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    vector<ll> dp(N + 1);
    dp[0] = 0;
    rep(i, N) {
        if (S[i] == '0') {
            dp[i + 1] = i;
        } else {
            dp[i + 1] = i - dp[i] + 1;
        }
    }

    ll sum = 0;
    rep(i, N + 1) sum += dp[i];
    cout << sum << endl;

    return 0;
}