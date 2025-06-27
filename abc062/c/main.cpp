#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;

    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1e18;
    // ||
    ans = min(ans, W);
    // =
    ans = min(ans, H);
    // T
    repp(i, 1, H) {
        int w1 = W / 2, w2 = W / 2;
        if (W % 2 == 1) w1++;

        ans = min(ans, max({abs(i * W - (H - i) * w1), abs(i * W - (H - i) * w2), abs((H - i) * w1 - (H - i) * w1)}));
    }
    // |-
    repp(i, 1, W) {
        int h1 = H / 2, h2 = H / 2;
        if (H % 2 == 1) h1++;

        ans = min(ans, max({abs(i * H - (W - i) * h1), abs(i * H - (W - i) * h2), abs((W - i) * h1 - (W - i) * h1)}));
    }

    cout << ans << endl;
}
