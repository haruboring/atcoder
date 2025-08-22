#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q, A, B;
    cin >> Q >> A >> B;

    set<int> apb, amb;
    apb.insert(A + B), amb.insert(A - B);
    rep(_, Q) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            apb.insert(a + b);
            amb.insert(a - b);
        } else {
            int ans = 1e18;
            auto itr = apb.lower_bound(a);
            if (itr != apb.end()) {
                if (*itr <= b) {
                    ans = 0;
                } else {
                    ans = min(ans, abs(*itr - b));
                }
            }
            if (itr != apb.begin()) {
                itr--;
                ans = min(ans, abs(a - *itr));
            }

            itr = amb.lower_bound(a);
            if (itr != amb.end()) {
                if (*itr <= b) {
                    ans = 0;
                } else {
                    ans = min(ans, abs(*itr - b));
                }
            }
            if (itr != amb.begin()) {
                itr--;
                ans = min(ans, abs(a - *itr));
            }

            cout << ans << endl;
        }
    }
}
