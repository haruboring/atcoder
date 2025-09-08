#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;

    set<int> s;
    s.insert(1e18);
    s.insert(-1e18);

    rep(i, Q) {
        int f, x;
        cin >> f >> x;

        if (f == 1) {
            s.insert(x);
        } else {
            auto itr = s.lower_bound(x);
            auto iitr = itr;
            iitr--;  // わからず。*(--itr)だとローカルは通るけどテストに通らん
            int ans = min(abs(x - *itr), abs(x - *(iitr)));

            if (ans > 1e10) ans = -1;
            cout << ans << endl;
        }
    }
}
