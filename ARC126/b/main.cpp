#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];

    vector<pair<int, int>> vp(M);
    rep(i, M) vp[i] = make_pair(a[i], -b[i]);

    sort(all(vp));
    rep(i, M) vp[i].second *= -1;

    vector<int> dp(0);

    for (auto p : vp) {
        int b = p.second;
        auto it = lower_bound(all(dp), b);
        if (it == dp.end()) {
            dp.push_back(b);
        } else {
            *it = b;
        }
    }

    cout << dp.size() << endl;
}
