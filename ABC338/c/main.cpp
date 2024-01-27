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

    rep(i, 1e6 + 100) {
        vector<int> Aq(N);
        int mi = 1e9;
        bool ok = true;
        rep(j, N) {
            Aq[j] = Q[j] - i * A[j];
            if (Aq[j] < 0) {
                ok = false;
                break;
            }
            if (B[j] != 0) {
                mi = min(mi, Aq[j] / B[j]);
            }
        }
        if (ok) {
            ans = max(ans, i + mi);
        }
    }

    cout << ans << endl;
}
