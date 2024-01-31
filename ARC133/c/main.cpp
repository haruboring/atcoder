#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<int> A(H), B(W);
    rep(i, H) cin >> A[i];
    rep(i, W) cin >> B[i];

    int a_sum = accumulate(all(A), 0LL), b_sum = accumulate(all(B), 0LL);
    if (a_sum % K != b_sum % K) {
        cout << -1 << endl;
        return 0;
    }

    int tmp1 = 0;
    rep(i, W) {
        tmp1 += (((K - 1) * H) - B[i] + K) % K;
    }
    int tmp2 = 0;
    rep(i, H) {
        tmp2 += (((K - 1) * W) - A[i] + K) % K;
    }

    cout << (K - 1) * H * W - max(tmp1, tmp2) << endl;
}
