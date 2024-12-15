#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N2, N3, N4;
        cin >> N2 >> N3 >> N4;

        int N2_, N3_, N4_;
        int cnt = 0;

        // 3
        cnt += min(N3 / 2, N4);
        N3_ = N3, N4_ = N4;
        N4 -= min(N3_ / 2, N4_);
        N3 -= min(N3_ / 2, N4_) * 2;
        cnt += min(N3 / 2, N2 / 2);
        N2 -= min(N3 / 2, N2 / 2) * 2;

        // 4
        cnt += min(N4 / 2, N2);
        N4_ = N4, N2_ = N2;
        N4 -= min(N4_ / 2, N2_) * 2;
        N2 -= min(N4_ / 2, N2_);
        cnt += min(N4, N2 / 3);
        N2 -= min(N4, N2 / 3) * 3;

        // 2
        cnt += N2 / 5;

        cout << cnt << endl;
    }
}
