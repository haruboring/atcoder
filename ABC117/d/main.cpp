#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> bit_cnt(50, 0);
    rep(i, N) {
        rep(j, 50) {
            if (A[i] & (1LL << j)) bit_cnt[j]++;
        }
    }

    int tmp = 1;
    rep(i, 50) {
        tmp *= 2;
    }
    int X = 0;
    rep(i, 50) {
        tmp /= 2;
        // 7 < 33
        if (X + tmp <= K && bit_cnt[49 - i] < N - bit_cnt[49 - i]) {
            X += tmp;
            debug(49 - i);
        }
    }
    debug(X);

    int ans = 0;
    rep(i, N) {
        ans += X ^ A[i];
        int a = X ^ A[i];
        debug(a);
    }

    cout << ans << endl;
}
