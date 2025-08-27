#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<pair<int, int>> XY(N);
    rep(i, N) XY[i] = {X[i], -Y[i]};
    sort(all(XY));

    vector<int> dp(N + 1, 1e18);
    dp[0] = 0;
    set<int> o;

    int ans = 0;
    rep(i, N) {
        auto [x, y] = XY[i];
        y *= -1;

        if (!o.count(x) && y > dp[ans]) ans++, o.insert(x);
        int idx = lower_bound(all(dp), y) - dp.begin();
        dp[idx] = y;
    }

    cout << ans << endl;
}
