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
    vector<int> Q(N), A(N), B(N);
    rep(i, N) cin >> Q[i];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int ans = 0;
    rep(a_cnt, 1000000 + 100) {
        int b_cnt = 1e18;
        bool ok = true;
        rep(i, N) {
            if (Q[i] - a_cnt * A[i] < 0) ok = false;
            if (B[i] != 0) b_cnt = min(b_cnt, (Q[i] - a_cnt * A[i]) / B[i]);
        }
        if (ok) ans = max(ans, a_cnt + b_cnt);
    }

    cout << ans << endl;
}
