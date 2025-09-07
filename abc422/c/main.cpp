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
        int na, nb, nc;
        cin >> na >> nb >> nc;

        int cnt = 0;
        cnt += min({na, nb, nc});
        na -= cnt, nb -= cnt, nc -= cnt;
        // 3,6
        int mi = min(na, nc);
        if (max(na, nc) >= 2 * mi) {
            cnt += mi;
        } else {
            cnt += (na + nc) / 3;
        }

        cout << cnt << endl;
    }
}
