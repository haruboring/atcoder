#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int fast_pow(int a, int b, int MOD) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N, M, K;
        cin >> N >> M >> K;

        if (N < K) {
            cout << fast_pow(2, N, 10) << endl;
            continue;
        }

        int d = M - K;
        if (d == 1) {
            cout << 0 << endl;
            continue;
        }

        int k = N - ((N - K) / d) * d;

        int ans = fast_pow(2, k, 10);
        cout << ans << endl;
    }
}
