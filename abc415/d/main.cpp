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
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    map<int, int> m;
    rep(i, M) {
        if (m[A[i]] == 0) {
            m[A[i]] = A[i] - B[i];
        } else {
            m[A[i]] = min(m[A[i]], A[i] - B[i]);
        }
    }

    set<pair<int, int>> s;
    for (auto [k, v] : m) {
        // cout << k << " dsav" << v << endl;
        s.insert({v, k});
    }

    int cnt = 0, tmp = 0;
    while (s.size() > 0) {
        auto [v, k] = *s.begin();
        int cnt_ = (N - k + v) / v;
        if (cnt_ < 0 || N < k) cnt_ = 0;
        cnt += cnt_;
        // debug(cnt);
        // debug(N);
        N = N - cnt_ * v;

        s.erase({v, k});
    }
    cout << cnt << endl;
}
