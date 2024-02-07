#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> r(N), c(N), a(N);
    rep(i, N) {
        cin >> r[i] >> c[i] >> a[i];
        r[i]--;
        c[i]--;
    }

    vector<tuple<int, int, int>> A;
    rep(i, N) A.push_back({a[i], r[i], c[i]});
    sort(all(A));
    reverse(all(A));
    map<pair<int, int>, int> ans;
    vector<set<int>> s(H), t(W);
    vector<int> dp(N);
    vector<tuple<int, int, int>> tmp;
    rep(i, N) {
        if (i != 0 && get<0>(A[i]) != get<0>(A[i - 1])) {
            for (auto [d, r, c] : tmp) {
                s[r].insert(d);
                t[c].insert(d);
            }
            tmp.clear();
        }
        auto [a, r, c] = A[i];
        if (!s[r].empty()) {
            dp[i] = max(dp[i], *s[r].rbegin() + 1);
        }
        if (!t[c].empty()) {
            dp[i] = max(dp[i], *t[c].rbegin() + 1);
        }
        ans[{r, c}] = dp[i];

        tmp.push_back({dp[i], r, c});
    }

    rep(i, N) {
        cout << ans[{r[i], c[i]}] << endl;
    }
}
