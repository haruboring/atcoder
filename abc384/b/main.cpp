#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, D;
    cin >> N >> D;
    vector<int> T(N), L(N);
    rep(i, N) cin >> T[i] >> L[i];

    repp(i, 1, D + 1) {
        int ans = -1;
        rep(j, N) {
            ans = max(ans, (L[j] + i) * T[j]);
        }

        cout << ans << endl;
    }
}
