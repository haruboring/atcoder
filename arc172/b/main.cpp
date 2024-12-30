#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, L;
    cin >> N >> K >> L;

    int MOD = 998244353;
    int d = N - K;

    int ans = 1;
    rep(i, N) {
        ans *= max({0LL, L - d, L - i});
        ans %= MOD;
    }

    cout << ans << endl;
}
